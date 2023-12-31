/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_shade_hit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:07:57 by arobu             #+#    #+#             */
/*   Updated: 2023/09/19 14:25:10 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "intersect.h"
#include "../light/light.h"
#include "scene.h"

static inline double	shlick(t_computations *computations);

t_color	intersect_shade_hit_threads(\
	t_scene *world, t_computations *computations, \
		int depth, t_thread_isect *isect)
{
	t_color			surface_color;
	t_color			reflected_color;
	t_color			refracted_color;
	t_real			reflectance;
	t_computations	comps;

	comps = *computations;
	comps.frac_intensity = light_intensity_at_threads(\
		world, &world->light, &comps.over_point, isect);
	surface_color = light_lightning(&comps, &world->light);
	reflected_color = intersect_reflected_color_threads(\
		world, isect, &comps, depth);
	refracted_color = intersect_refracted_color_threads(\
		world, isect, &comps, depth);
	if (comps.shape->material.reflectivity > 0 && \
		comps.shape->material.transparency > 0)
	{
		reflectance = shlick(&comps);
		return (tuple_add(surface_color, \
				tuple_add(color_multiply_s(reflected_color, reflectance), \
				color_multiply_s(refracted_color, 1 - reflectance))));
	}
	return (tuple_add(surface_color, \
			tuple_add(reflected_color, \
				refracted_color)));
}

static inline double	shlick(t_computations *computations)
{
	t_real			cos_angle;
	t_real			sin2t;
	t_real			n;
	t_real			cos_t;
	t_real			r0;

	cos_angle = tuple_dot(computations->eye, computations->normal);
	if (computations->n1 > computations->n2)
	{
		n = computations->n1 / computations->n2;
		sin2t = n * n * (1.0 - (cos_angle * cos_angle));
		if (sin2t > 1.0)
			return (1.0);
		cos_t = sqrt(1.0 - sin2t);
		cos_angle = cos_t;
	}
	r0 = pow((computations->n1 - computations->n2) / \
		(computations->n1 + computations->n2), 2);
	return (r0 + (1 - r0) * pow(1.0 - cos_angle, 5));
}
