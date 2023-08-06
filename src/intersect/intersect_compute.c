/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_compute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:30:00 by arobu             #+#    #+#             */
/*   Updated: 2023/08/05 19:30:00 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "ray.h"
#include "shape.h"
#include "tuple.h"

bool intersect_compute(t_intersect *intersect, t_ray *ray, t_computations *comps)
{
	comps->normal = intersect->obj->vtable.normal_at(intersect->obj, comps->point);
	comps->shape = intersect->obj;
	comps->eye = tuple_negate(ray->direction);
	intersect_set_normal(comps);
	comps->over_point = tuple_add(comps->point, tuple_multiply_s(comps->normal, M_EPSILON));
	return (true);
}