/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk_intersect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 19:49:11 by arobu             #+#    #+#             */
/*   Updated: 2023/08/12 19:49:11 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disk.h"
#include "ray.h"
#include "tuple.h"

bool	disk_intersect(t_shape *shape, t_ray ray, t_vector *intersections)
{
	t_real	t;
	t_tuple	point;
	double	radius;

	ray = ray_to_object_space(&ray, shape->transform);
	if (is_approx_equal(ray.direction.y, 0.0, M_EPSILON))
		return (false);
	t = -ray.origin.y / ray.direction.y;
	point = ray_at(ray, t);
	radius = point.x * point.x + point.z * point.z;
	if (radius <= 1.0)
	{
		vector_pushback_intersect(intersections, t, shape);
		return (true);
	}
	return (false);
}