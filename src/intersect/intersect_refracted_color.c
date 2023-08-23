/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_refracted_color.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:42:21 by arobu             #+#    #+#             */
/*   Updated: 2023/08/23 13:37:22 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "intersect.h"
#include "material.h"
#include "shape.h"
#include <math.h>

t_color	intersect_refracted_color_threads(\
	t_scene *world, t_thread_isect *isect, t_computations *comps, int depth)
{
	t_refracted_params	p;

	if (depth <= 0 || comps->shape->material.transparency == 0)
		return (color_new(0.0, 0.0, 0.0));
	p.n_ratio = comps->n1 / comps->n2;
	p.cosi = tuple_dot(comps->eye, comps->normal);
	p.sin2t = (p.n_ratio * p.n_ratio) * (1.0 - (p.cosi * p.cosi));
	if (p.sin2t > 1.0)
		return (color_new(0, 0, 0));
	p.cos_t = sqrt(1.0 - p.sin2t);
	p.direction = tuple_subtract(\
		tuple_multiply_s(comps->normal, p.n_ratio * p.cosi - p.cos_t), \
		tuple_multiply_s(comps->eye, p.n_ratio));
	p.refracted_ray = ray_new(comps->under_point, p.direction);
	p.color = color_multiply_s(\
		intersect_color_at_threads(world, &p.refracted_ray, depth - 1, isect), \
			comps->shape->material.transparency);
	return (p.color);
}
