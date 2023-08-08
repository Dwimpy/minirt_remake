/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_refracted_color.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 19:17:53 by arobu             #+#    #+#             */
/*   Updated: 2023/08/08 19:17:53 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "ray.h"
#include "shape.h"

t_color	intersect_refracted_color(t_vector *world, t_computations *comps, t_light *light, int depth)
{
	t_material	material;
	double		n_ratio;
	double		sint;
	double		cosi;
	double		cost;
	t_tuple		direction;

	material = comps->shape->material;
	if (is_approx_equal(material.transparency, 0, M_EPSILON) || depth <= 0)
		return (color_new(0, 0, 0));
	n_ratio = comps->n1 / comps->n2;
	cosi = tuple_dot(comps->eye, comps->normal);
	sint = n_ratio * n_ratio * (1.0 - cosi * cosi);
	if (sint > 1.0)
		return (color_new(0, 0, 0));
	cost = sqrt(1.0 - sint);
	direction = tuple_subtract(\
		tuple_multiply_s(comps->normal, n_ratio * cosi - cost), \
		tuple_multiply_s(comps->eye, n_ratio));
	return (color_multiply_s(\
		intersect_color_at(world, \
			ray_new(comps->under_point, direction), \
				comps, light, depth - 1), material.transparency));
}