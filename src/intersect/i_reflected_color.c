/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_reflected_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:31:43 by arobu             #+#    #+#             */
/*   Updated: 2023/08/10 16:36:03 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "intersect.h"
#include "material.h"
#include "ray.h"
#include "tuple.h"
#include "scene.h"
#include "shape.h"

t_color	intersect_reflected_color(t_scene *world, t_computations *comps, int depth)
{
	t_ray		reflected_ray;
	t_color		black;
	t_color		color;

	if (comps->shape->material.reflectivity == 0.0 || depth <= 0)
		return (color_new(0, 0, 0));
	reflected_ray = ray_new(comps->over_point, comps->reflected_dir);
	color = color_multiply_s(intersect_color_at(world, &reflected_ray, depth - 1), comps->shape->material.reflectivity);
	return (color);
}