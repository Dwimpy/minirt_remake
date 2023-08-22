/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:59:00 by arobu             #+#    #+#             */
/*   Updated: 2023/08/22 22:26:43 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "camera.h"
#include "color.h"
#include "image.h"
#include "intersect.h"
#include "sampling.h"
#include "scene.h"
#include "sphere.h"
#include "tile.h"
#include "renderer.h"
#define SPP 2.0

static void	scene_render_vector_free(t_thread_isect *isect);
static void	process_and_render(\
	t_scene *world, t_renderer *renderer, \
		t_thread_params *p, t_thread_isect *isect);
static void	scene_render_pixels(\
	t_scene *world, t_renderer *renderer, \
		t_thread_isect *isect, t_thread_params *p);

void	scene_render(t_scene *world, t_renderer *renderer)
{
	t_thread_isect	isect;
	t_thread_params	p;

	process_and_render(world, renderer, &p, &isect);
	scene_render_vector_free(&isect);
}

static void	process_and_render(\
	t_scene *world, t_renderer *renderer, \
		t_thread_params *p, t_thread_isect *isect)
{
	p->j = 0;
	isect->intersections = vector_init(10, sizeof(t_intersect));
	isect->shadow_isect = vector_init(10, sizeof(t_intersect));
	isect->comps.ref_index_tracker = vector_init(10, sizeof(t_intersect));
	scene_render_pixels(world, renderer, isect, p);
}

static void	scene_render_pixels(\
	t_scene *world, t_renderer *renderer, \
		t_thread_isect *isect, t_thread_params *p)
{
	while (p->j < renderer->canvas.height - 1)
	{
		p->i = 0;
		printf("Render: %.2f\n", (t_real)p->j / renderer->canvas.height * 100);
		while (p->i < renderer->canvas.width - 1)
		{
			p->k = 0;
			p->color = color_new(0, 0, 0);
			while (p->k < (size_t) SPP)
			{
				p->ray = camera_get_ray(\
					&world->camera, p->i, p->j, renderer->samples[p->k]);
				p->color = color_add(p->color, color_multiply_s(\
					intersect_color_at_threads(\
						world, &p->ray, 5, isect), 1.0 / SPP));
				++p->k;
			}
			image_set_pixel(&renderer->canvas, p->color, p->i, p->j);
			++p->i;
		}
		++p->j;
	}
}

static void	scene_render_vector_free(t_thread_isect *isect)
{
	vector_free(&isect->intersections);
	vector_free(&isect->shadow_isect);
	vector_free(&isect->comps.ref_index_tracker);
}
