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
#include "scene.h"
#include <sys/_types/_size_t.h>

void	scene_render(t_scene *world, t_camera *camera, t_image *canvas)
{
	t_ray	ray;
	t_color	color;
	size_t	i;
	size_t	j;

	j = -1;
	while (++j < canvas->height - 1)
	{
		i = -1;
		while (++i < canvas->width - 1)
		{
			ray = camera_get_ray(camera, i, j);
			color = intersect_color_at(world, &ray);
			image_set_pixel(*canvas, color, i, j);
		}
	}
}