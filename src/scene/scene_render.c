/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:59:00 by arobu             #+#    #+#             */
/*   Updated: 2023/08/10 14:06:01 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "color.h"
#include "image.h"
#include "intersect.h"
#include "sampling.h"
#include "scene.h"
#include "sphere.h"
#define SPP 4

void	scene_render(t_scene *world, t_camera *camera, t_image *canvas)
{
	t_ray		ray;
	t_color		color;
	size_t		i;
	size_t		j;
	size_t		k;
	t_sample	*samples;

	j = 0;
	samples = sample_jittered_new(SPP);
	cubic_spline_filter(samples, SPP);
	while (j < canvas->height - 1)
	{
		printf("Rendering: %.2f%%\n", ((double)j / (canvas->height - 1)) * 100);
		i = 0;
		while (i < canvas->width - 1)
		{
			k = 0;
			color = color_new(0, 0, 0);
			while (k < SPP)
			{
				ray = camera_get_ray(camera, i, j, samples[k]);
				color = color_multiply_s(intersect_color_at(world, &ray, 5), 1.0 / SPP);
				++k;
			}
			image_set_pixel(*canvas, color, i, j);
			++i;
		}
		++j;
	}
}
