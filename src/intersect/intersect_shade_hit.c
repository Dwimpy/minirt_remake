/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_shade_hit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:59:36 by arobu             #+#    #+#             */
/*   Updated: 2023/08/09 05:12:29 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "light.h"
#include "material.h"
#include "shape.h"

static t_real	shlick_method(t_computations *comps);

t_color	intersect_shade_hit(\
	t_vector *world, t_light *light, t_computations *comps, int depth)
{
	t_color		surface;
	t_color		reflected;
	t_color		refracted;
	t_real		reflectance;
	t_material	material;

	material = comps->shape->material;
	intersect_is_shadowed(world, light, comps);
	surface = light_lightning(light, comps);
	reflected = intersect_reflected_color(world, comps, light, depth);
	refracted = intersect_refracted_color(world, comps, light, depth);
	if (material.reflectivity > 0 && material.transparency > 0)
	{
		reflectance = shlick_method(comps);
		return (color_add(\
				color_add(surface, \
					color_multiply_s(reflected, reflectance)), \
						color_multiply_s(refracted, 1 - reflectance)));
	}
	return (color_add(color_add(\
		surface, \
		reflected), \
		refracted));
}

static t_real	shlick_method(t_computations *comps)
{
	double	cos;
	double	n;
	double	sint;
	double	cost;
	double	r;
	double	omc;

	cos = tuple_dot(comps->eye, comps->normal);
	if (comps->n1 > comps->n2)
	{
		n = comps->n1 / comps->n2;
		sint = n * n * (1.0 - cos * cos);
		if (sint > 1.0)
			return (1.0);
		cost = sqrt(1.0 - sint);
		cos = cost;
	}
	r = ((comps->n1 - comps->n2) / (comps->n1 + comps->n2)) * \
		((comps->n1 - comps->n2) / (comps->n1 + comps->n2));
	omc = (1.0 - cos);
	return (r + (1.0 - r) * (omc * omc * omc * omc * omc));
}
