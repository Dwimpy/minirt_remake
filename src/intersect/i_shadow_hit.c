/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_shadow_hit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:17:38 by arobu             #+#    #+#             */
/*   Updated: 2023/08/10 14:48:37 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "ray.h"
#include "tuple.h"
#include "scene.h"
#include "vector.h"
#include <sys/_types/_size_t.h>

bool	intersect_shadow_hit(t_scene *world, t_computations *computations)
{
	t_tuple		r_to_light;
	t_ray		shadow_ray;
	t_real		distance;
	t_tuple		direction;
	t_intersect	*i;
	size_t		idx;

	idx = 0;
	r_to_light = tuple_subtract(world->light.origin, computations->over_point);
	distance = tuple_magnitude(r_to_light);
	direction = tuple_normalize(r_to_light);
	shadow_ray = ray_new(computations->over_point, direction);
	vector_clear(&world->shadow_intersections);
	intersect_shadow_world(world, &shadow_ray);
	i = intersect_hit(&world->shadow_intersections);
	if (i && i->t < distance)
		return (true);
	return (false);
}