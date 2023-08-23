/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_compute.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:39:29 by arobu             #+#    #+#             */
/*   Updated: 2023/08/23 13:26:46 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "shape.h"

inline static void	intersect_set_normal(t_computations *comps);
inline static void	handle_refraction_index(\
	t_computations *comps, t_intersect *i, t_vector *isect);
inline static bool	compute_n2(\
	t_computations *comps, t_intersect *intersect, \
		t_intersect *i, t_shape **shape);
inline static void	compute_n1_and_remove_if(\
	t_computations *comps, t_intersect *intersect, \
		t_intersect *i, t_shape **shape);

void	intersect_compute(\
	t_intersect *i, t_ray *ray, t_computations *comps, t_vector	*intersections)
{
	comps->t = i->t;
	comps->shape = i->obj;
	comps->point = ray_at(*ray, comps->t);
	comps->eye = tuple_negate(ray->direction);
	comps->normal = comps->shape->vtable.normal_at(comps->shape, comps->point);
	intersect_set_normal(comps);
	comps->over_point = tuple_add(\
		comps->point, tuple_multiply_s(comps->normal, M_EPSILON));
	comps->under_point = tuple_subtract(\
		comps->point, tuple_multiply_s(comps->normal, M_EPSILON));
	comps->reflected_dir = tuple_reflect(\
		ray->direction, comps->normal);
	handle_refraction_index(comps, i, intersections);
}

inline static void	handle_refraction_index(\
	t_computations *comps, t_intersect *i, t_vector *isect)
{
	size_t		idx;
	t_intersect	*intersect;
	t_shape		**shape;

	idx = 0;
	shape = NULL;
	if (!isect)
		return ;
	vector_clear(&comps->ref_index_tracker);
	while (idx < isect->size)
	{
		intersect = vector_at(isect, idx);
		compute_n1_and_remove_if(comps, intersect, i, shape);
		if (compute_n2(comps, intersect, i, shape))
			break ;
		idx++;
	}
}

inline static void	compute_n1_and_remove_if(\
	t_computations *comps, t_intersect *intersect, \
		t_intersect *i, t_shape **shape)
{
	if (intersect->t == i->t)
	{
		if (comps->ref_index_tracker.size == 0)
			comps->n1 = 1.0;
		else
		{
			shape = (t_shape **)vector_back(&comps->ref_index_tracker);
			comps->n1 = (*shape)->material.refractive_index;
		}
	}
	if (!vector_remove_element_if(\
			&comps->ref_index_tracker, \
			vector_comparator_shape, &intersect->obj))
		vector_pushback(&comps->ref_index_tracker, &intersect->obj);
}

inline static bool	compute_n2(\
	t_computations *comps, t_intersect *intersect, \
		t_intersect *i, t_shape **shape)
{
	if (intersect->t == i->t)
	{
		if (comps->ref_index_tracker.size == 0)
			comps->n2 = 1.0;
		else
		{
			shape = (t_shape **)vector_back(&comps->ref_index_tracker);
			comps->n2 = (*shape)->material.refractive_index;
		}
		return (true);
	}
	return (false);
}

inline static void	intersect_set_normal(t_computations *comps)
{
	if (tuple_dot(comps->eye, comps->normal) < 0.0)
	{
		comps->normal = tuple_negate(comps->normal);
	}
}
