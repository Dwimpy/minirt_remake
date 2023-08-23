/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_world.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:19:25 by arobu             #+#    #+#             */
/*   Updated: 2023/08/22 18:05:10 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "scene.h"

void	intersect_world_threads(\
	t_scene *world, t_thread_isect *intersections, t_ray *ray_thread)
{
	t_vector_iterator	it;
	t_shape				*shape;

	vector_iterator_begin(&it, &world->objs);
	while (!it.end(&it))
	{
		shape = it.get(&it);
		shape->vtable.intersect(\
			shape, *ray_thread, &intersections->intersections);
		it.next(&it);
	}
}

void	intersect_shadow_world_threads(\
	t_scene *world, t_thread_isect *isect, t_ray *ray)
{
	t_vector_iterator	it;
	t_shape				*shape;

	vector_iterator_begin(&it, &world->objs);
	while (!it.end(&it))
	{
		shape = it.get(&it);
		shape->vtable.intersect(shape, *ray, &isect->shadow_isect);
		it.next(&it);
	}
}
