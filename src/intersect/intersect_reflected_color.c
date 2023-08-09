/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_reflected_color.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:56:34 by arobu             #+#    #+#             */
/*   Updated: 2023/08/09 05:08:55 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "material.h"
#include "ray.h"
#include "shape.h"

t_color	intersect_reflected_color(t_vector *world, t_computations *comps, t_light *light, int depth)
{
	t_material	material;
	t_ray		ray;
	t_color		black;

	black = color_new(0, 0, 0);
	material = shape_get_material(comps->shape);
	if (material.reflectivity == 0 || depth <= 0)
		return (black);
	ray = ray_new(comps->over_point, comps->reflected_dir);
	return (color_multiply_s(\
		intersect_color_at(world, ray, comps, light, depth - 1), \
		material.reflectivity));
}
