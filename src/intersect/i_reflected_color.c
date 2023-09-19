/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_reflected_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:31:43 by arobu             #+#    #+#             */
/*   Updated: 2023/09/19 13:34:28 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "intersect.h"
#include "material.h"
#include "scene.h"

t_color	intersect_reflected_color_threads(\
	t_scene *world, t_thread_isect *isect, t_computations *comps, int depth)
{
	t_ray		reflected_ray;
	t_color		color;

	if (comps->shape->material.reflectivity == 0.0 || depth <= 0)
		return (color_new(0, 0, 0));
	reflected_ray = ray_new(comps->over_point, comps->reflected_dir);
	color = color_multiply_s(\
		intersect_color_at_threads(\
			world, &reflected_ray, depth - 1, isect), \
				comps->shape->material.reflectivity);
	return (color);
}
