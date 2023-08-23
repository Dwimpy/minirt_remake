/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:18:25 by arobu             #+#    #+#             */
/*   Updated: 2023/08/23 16:39:32 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "plane.h"

static bool	plane_add_intersection(\
	t_shape *shape, t_ray ray, t_vector *intersections)
{
	vector_pushback_intersect(\
		intersections, -ray.origin.y / ray.direction.y, shape);
	return (true);
}

bool	plane_intersect(t_shape *shape, t_ray ray, t_vector *intersections)
{
	ray = ray_to_object_space(&ray, shape->transform);
	if (is_approx_equal(ray.direction.y, 0.0, M_EPSILON))
		return (false);
	return (plane_add_intersection(shape, ray, intersections));
}
