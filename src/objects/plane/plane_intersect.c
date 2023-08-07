/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:18:25 by arobu             #+#    #+#             */
/*   Updated: 2023/08/07 19:18:25 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "matrix.h"
#include "plane.h"
#include "ray.h"
#include "tuple.h"
#include "vector.h"

static bool plane_add_intersection(t_shape *shape, t_ray ray, t_vector *intersections)
{
	vector_pushback_intersect(\
		intersections, -ray.origin.y / ray.direction.y, shape);
	return (true);
}

bool plane_intersect(t_shape *shape, t_ray ray, t_vector *intersections)
{
	ray = ray_to_object_space(&ray, shape->transform);
	if (tuple_equal_s(ray.direction, M_EPSILON))
		return (false);
	return (plane_add_intersection(shape, ray, intersections));
}
