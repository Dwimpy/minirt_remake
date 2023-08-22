/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 22:18:52 by arobu             #+#    #+#             */
/*   Updated: 2023/08/22 21:57:49 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "scene.h"
#include "tile.h"
#include <pthread.h>
#include <stdio.h>
#include "renderer.h"

static void	render_curr_tile(\
	t_thread_args *args, t_thread_isect *isect, t_thread_params *params);
static void	thread_check_exit_or_render(\
	t_renderer *renderer, t_thread_isect *isect, t_thread_params *p);
static void	free_thread_data(t_thread_isect *isect);

void	render_tile(t_thread_args *args)
{
	t_thread_isect	thread_isect;
	t_thread_params	params;

	thread_isect.intersections = vector_init(10, sizeof(t_intersect));
	thread_isect.shadow_isect = vector_init(10, sizeof(t_intersect));
	thread_isect.comps.ref_index_tracker = vector_init(10, sizeof(t_intersect));
	while (args->renderer->tiles.size > 0)
	{
		pthread_mutex_lock(&args->renderer->mutex);
		params.tile = vector_back(&args->renderer->tiles);
		args->renderer->tiles.size--;
		pthread_mutex_unlock(&args->renderer->mutex);
		params.j = params.tile->corner.y;
		render_curr_tile(args, &thread_isect, &params);
	}
	free_thread_data(&thread_isect);
}

static void	render_curr_tile(\
	t_thread_args *args, t_thread_isect *isect, t_thread_params *params)
{
	while (params->j < params->tile->corner.y + params->tile->dim.height)
	{
		params->i = params->tile->corner.x;
		while (params->i < params->tile->corner.x + params->tile->dim.w)
		{
			params->k = 0;
			params->color = color_new(0, 0, 0);
			while (params->k < (size_t) args->renderer->samples_per_pixel)
			{
				params->ray = camera_get_ray(\
				&args->world->camera, params->i, params->j, \
					args->renderer->samples[params->k]);
				params->color = color_add(params->color, color_multiply_s(\
				intersect_color_at_threads(args->world, &params->ray, 5, \
					isect), 1.0 / args->renderer->samples_per_pixel));
				++params->k;
			}
			thread_check_exit_or_render(args->renderer, isect, params);
		}
		++params->j;
	}
}

static void	thread_check_exit_or_render(\
	t_renderer *renderer, t_thread_isect *isect, t_thread_params *p)
{
	pthread_mutex_lock(&renderer->mutex);
	if (renderer->exiting == 1)
	{
		pthread_mutex_unlock(&renderer->mutex);
		free_thread_data(isect);
		pthread_exit(NULL);
	}
	image_set_pixel(&renderer->canvas, p->color, p->i, p->j);
	pthread_mutex_unlock(&renderer->mutex);
	++p->i;
}

static void	free_thread_data(t_thread_isect *isect)
{
	vector_free(&isect->intersections);
	vector_free(&isect->shadow_isect);
	vector_free(&isect->comps.ref_index_tracker);
}

void	*render_tiles(void *arg)
{
	t_thread_args	*thread_args;
	size_t			i;

	thread_args = (t_thread_args *)arg;
	i = 0;
	while (i < NUM_THREADS)
	{
		render_tile(thread_args);
		i++;
	}
	return (NULL);
}
