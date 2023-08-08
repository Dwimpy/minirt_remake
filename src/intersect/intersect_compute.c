/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_compute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:30:00 by arobu             #+#    #+#             */
/*   Updated: 2023/08/08 18:53:16 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "material.h"
#include "ray.h"
#include "shape.h"
#include "tuple.h"
#include "vector.h"

static void	handle_refractive_index(t_computations *comps);

bool intersect_compute(t_intersect *intersect, t_ray *ray, t_computations *comps)
{
	comps->normal = \
		intersect->obj->vtable.normal_at(intersect->obj, comps->point);
	comps->shape = intersect->obj;
	comps->eye = tuple_negate(ray->direction);
	intersect_set_normal(comps);
	comps->over_point = \
		tuple_add(comps->point, tuple_multiply_s(comps->normal, M_EPSILON));
	comps->under_point = \
		tuple_subtract(comps->point, \
		tuple_multiply_s(comps->normal, M_EPSILON));
	comps->reflected_dir = tuple_reflect(ray->direction, comps->normal);
//	handle_refractive_index(comps);
	return (true);
}

static void	handle_refractive_index(t_computations *comps)
{
	t_shape		*shape;
	size_t		i;

	shape = vector_back(&comps->ref_index_tracker);
	if (!shape)
		comps->n1 = 1.0;
	else
		comps->n1 = shape->material.refractive_index;
	if (shape && comps->shape->id == shape->id)
		vector_remove_front(&comps->ref_index_tracker);
	else
		vector_pushback(&comps->ref_index_tracker, comps->shape);
	shape = vector_back(&comps->ref_index_tracker);
	if (!shape)
		comps->n2 = 1.0;
	else
		comps->n2 = shape->material.refractive_index;
}
