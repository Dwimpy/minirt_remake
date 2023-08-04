/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_world.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:47:10 by arobu             #+#    #+#             */
/*   Updated: 2023/08/04 14:47:10 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "shape.h"

void	intersect_world(t_vector *world, t_ray ray, t_intersections *isect_ptr, t_intersections *intersections)
{
	t_vector_iterator	it;
	t_shape				*curr_shape;

	vector_iterator_begin(&it, world);
	intersections->count = 0;
	while (!it.end(&it))
	{
		curr_shape = (t_shape *)it.get(&it);
		curr_shape->vtable.intersect(curr_shape, ray, intersections);
		it.next(&it);
	}
	isect_ptr = intersections;
}