/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 22:18:52 by arobu             #+#    #+#             */
/*   Updated: 2023/08/22 17:39:53 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "tile.h"
#include <pthread.h>
#include <stdio.h>
#include "renderer.h"

void render_tile(t_thread_args *args)
{
	t_ray ray;
	t_color color;
	size_t i;
	size_t j;
	size_t k;
	t_tile *tile;
	t_thread_isect thread_isect;
	thread_isect.intersections = vector_init(10, sizeof(t_intersect));
	thread_isect.shadow_isect = vector_init(10, sizeof(t_intersect));
	thread_isect.comps.ref_index_tracker = vector_init(10, sizeof(t_intersect));
	while (args->renderer->tiles.size > 0)
	{
		pthread_mutex_lock(&args->renderer->mutex);
		tile = vector_back(&args->renderer->tiles);
		args->renderer->tiles.size--;
		pthread_mutex_unlock(&args->renderer->mutex);
		j = tile->corner.y;
		while (j < tile->corner.y + tile->dim.height)
		{
			i = tile->corner.x;
			while (i < tile->corner.x + tile->dim.w)
			{
				k = 0;
				color = color_new(0, 0, 0);
				while (k < (size_t) args->renderer->samples_per_pixel)
				{
					ray = camera_get_ray(&args->world->camera, i, j, args->renderer->samples[k]);
					color = color_add(color, color_multiply_s(intersect_color_at_threads(args->world, &ray, 5, &thread_isect), 1.0 / args->renderer->samples_per_pixel));
					++k;
				}
				pthread_mutex_lock(&args->renderer->mutex);
				if (args->renderer->exiting == 1)
				{
					pthread_mutex_unlock(&args->renderer->mutex);
					vector_free(&thread_isect.intersections);
					vector_free(&thread_isect.shadow_isect);
					vector_free(&thread_isect.comps.ref_index_tracker);
					pthread_exit(NULL);
				}
				image_set_pixel(&args->renderer->canvas, color, i, j);
				pthread_mutex_unlock(&args->renderer->mutex);
				++i;
			}
			++j;
		}
	}
	vector_free(&thread_isect.intersections);
	vector_free(&thread_isect.shadow_isect);
	vector_free(&thread_isect.comps.ref_index_tracker);
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