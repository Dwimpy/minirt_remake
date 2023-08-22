/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_color_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:21:24 by arobu             #+#    #+#             */
/*   Updated: 2023/08/09 21:21:24 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "intersect.h"
#include "scene.h"
#include "vector.h"

t_color	intersect_color_at(t_scene *world, t_ray *ray, int depth)
{
	t_intersect	*i;
	t_color		color;

	vector_clear(&world->intersections);
	intersect_world(world, ray);
	i = intersect_hit(&world->intersections);
	if (i)
	{
		intersect_compute(i, ray, &world->comps, &world->intersections);
		color = intersect_shade_hit(world, &world->comps, depth);
		return (color);
	}
	return (color_new(0, 0, 0));
}

t_color	intersect_color_at_threads(t_scene *world, t_ray *ray, int depth, t_thread_isect *intersections)
{
	t_intersect	*i;
	t_color		color;
	t_ray		ray_thread;

	ray_thread = *ray;
	vector_clear(&intersections->intersections);
	intersect_world_threads(world, intersections, &ray_thread);
	i = intersect_hit(&intersections->intersections);
	if (i)
	{
		intersect_compute(i, &ray_thread, &intersections->comps, &intersections->intersections);
		color = intersect_shade_hit_threads(world, &intersections->comps, depth, intersections);
		return (color);
	}
	return (color_new(0, 0, 0));
}
