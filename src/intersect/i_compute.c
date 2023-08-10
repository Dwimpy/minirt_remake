/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_compute.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:39:29 by arobu             #+#    #+#             */
/*   Updated: 2023/08/09 19:59:46 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "shape.h"
#include "tuple.h"

inline static void	intersect_set_normal(t_computations *comps);

void	intersect_compute(t_intersect *i, t_ray *ray, t_computations *comps)
{
	comps->t = i->t;
	comps->shape = i->obj;
	comps->point = ray_at(*ray, comps->t);
	comps->eye = tuple_negate(ray->direction);
	comps->normal = comps->shape->vtable.normal_at(comps->shape, comps->point);
	intersect_set_normal(comps);
	comps->over_point = tuple_add(comps->point, tuple_multiply_s(comps->normal, M_EPSILON));
	comps->reflected_dir = tuple_reflect(ray->direction, comps->normal);
}

inline static void	intersect_set_normal(t_computations *comps)
{
	if (tuple_dot(comps->eye, comps->normal) < 0.0)
	{
		comps->inside = true;
		comps->normal = tuple_negate(comps->normal);
	}
	else
		comps->inside = false;
}