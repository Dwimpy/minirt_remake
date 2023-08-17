/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_refracted_color.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:42:21 by arobu             #+#    #+#             */
/*   Updated: 2023/08/10 22:42:21 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "intersect.h"
#include "material.h"
#include "shape.h"
#include "tuple.h"
#include <complex.h>
#include <math.h>

t_color	intersect_refracted_color(t_scene *world, t_computations *comps, int depth)
{
	t_real n_ratio;
	t_real cosi;
	t_real sin2t;
	t_real cos_t;
	t_tuple direction;
	t_ray refracted_ray;
	t_color	color;
	t_material	material;

	if (depth <= 0 || comps->shape->material.transparency == 0)
		return (color_new(0.0, 0.0, 0.0));
	n_ratio = comps->n1 / comps->n2;
	cosi = tuple_dot(comps->eye, comps->normal);
	sin2t = (n_ratio * n_ratio) * (1.0 - (cosi * cosi));
	if (sin2t > 1.0)
		return (color_new(0, 0, 0));
	cos_t = sqrt(1.0 - sin2t);
	direction = tuple_subtract(tuple_multiply_s(comps->normal, n_ratio * cosi - cos_t), \
            tuple_multiply_s(comps->eye, n_ratio));
	refracted_ray = ray_new(comps->under_point, direction);
	color = color_multiply_s(\
		intersect_color_at(world, &refracted_ray, depth - 1), \
			comps->shape->material.transparency);
	return (color);
}