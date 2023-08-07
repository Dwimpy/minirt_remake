/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_is_shadowed.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 18:11:17 by arobu             #+#    #+#             */
/*   Updated: 2023/08/06 18:11:17 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "ray.h"
#include "tuple.h"
#include "light.h"

bool intersect_is_shadowed(t_vector *world, t_light *light, t_computations *comps)
{
	t_tuple	point_to_light;
	t_tuple	dir;
	t_real	dist;
	t_ray	new_ray;

	point_to_light = tuple_subtract(light->origin, comps->over_point);
	dist = tuple_magnitude(point_to_light);
	dir = tuple_normalize(point_to_light);
	new_ray = ray_new(comps->over_point, dir);
	intersect_world(world, new_ray, &comps->shadow_intersections);
	return (intersect_shadow_hit(&new_ray, comps, &dist));
}
