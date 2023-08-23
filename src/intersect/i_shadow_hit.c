/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_shadow_hit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:17:38 by arobu             #+#    #+#             */
/*   Updated: 2023/08/18 16:02:30 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "scene.h"

bool	intersect_shadow_hit_threads(\
	t_scene *world, t_tuple *light_pos, \
		t_tuple *point, t_thread_isect *isect)
{
	t_tuple		r_to_light;
	t_ray		shadow_ray;
	t_real		distance;
	t_tuple		direction;
	t_intersect	*i;

	r_to_light = tuple_subtract(*light_pos, *point);
	distance = tuple_magnitude(r_to_light);
	direction = tuple_normalize(r_to_light);
	shadow_ray = ray_new(*point, direction);
	vector_clear(&isect->shadow_isect);
	intersect_shadow_world_threads(world, isect, &shadow_ray);
	i = intersect_hit(&isect->shadow_isect);
	if (i && i->t < distance)
		return (true);
	return (false);
}
