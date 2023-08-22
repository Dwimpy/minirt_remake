/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:59:00 by arobu             #+#    #+#             */
/*   Updated: 2023/08/21 22:31:47 by arobu            ###   ########.fr       */
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

void scene_render(t_scene *world, t_renderer *renderer)
{
	t_ray ray;
	t_color color;
	size_t i;
	size_t j;
	size_t k;

	j = 0;
	while (j < renderer->canvas.height - 1)
	{
		i = 0;
		printf("Rendering: [ %.2f%% ]\n", ((t_real) j / renderer->canvas.height) * 100);
		while (i < renderer->canvas.width - 1)
		{
			k = 0;
			color = color_new(0, 0, 0);
			while (k < (size_t) SPP)
			{
				ray = camera_get_ray(&world->camera, i, j, renderer->samples[k]);
				color = color_add(color, color_multiply_s(intersect_color_at(world, &ray, 5), 1.0 / SPP));
				++k;
			}
			image_set_pixel(&renderer->canvas, color, i, 0);
			++i;
		}
		++j;
	}
}
