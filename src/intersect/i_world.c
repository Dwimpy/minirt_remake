/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_world.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:19:25 by arobu             #+#    #+#             */
/*   Updated: 2023/08/09 19:19:25 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "scene.h"
#include "shape.h"

void	intersect_world(t_scene *world, t_ray *ray)
{
	t_vector_iterator	it;
	t_shape				*shape;
	t_vector			intersections;

	vector_iterator_begin(&it, &world->objs);
	while (!it.end(&it))
	{
		shape = it.get(&it);
		shape->vtable.intersect(shape, *ray, &world->intersections);
		it.next(&it);
	}
}

t_vector	intersect_world_test(t_scene *world, t_ray *ray)
{
	t_vector_iterator	it;
	t_shape				*shape;
	t_vector			intersections;

	intersections = vector_init(10, sizeof(t_intersect));
	vector_iterator_begin(&it, &world->objs);
	while (!it.end(&it))
	{
		shape = it.get(&it);
		shape->vtable.intersect(shape, *ray, &intersections);
		it.next(&it);
	}
	return (intersections);
}

void	intersect_shadow_world(t_scene *world, t_ray *ray)
{
	t_vector_iterator	it;
	t_shape				*shape;

	vector_iterator_begin(&it, &world->objs);
	while (!it.end(&it))
	{
		shape = it.get(&it);
		shape->vtable.intersect(shape, *ray, &world->shadow_intersections);
		it.next(&it);
	}
}