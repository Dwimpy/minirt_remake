/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_normal_at.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:42:30 by arobu             #+#    #+#             */
/*   Updated: 2023/08/12 15:42:30 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

t_tuple	cylinder_normal_at(t_shape *shape, t_tuple isec_point)
{
	const t_cylinder	*cyl = shape_get_data(shape);
	t_tuple				local_point;
	t_tuple				normal;
	t_real				distance;

	local_point = matrix_multiply_tuple(shape->transform.inv_tf, isec_point);
	distance = local_point.x * local_point.x + local_point.z * local_point.z;
	if (distance < 1 && fabs(local_point.y - cyl->bounds.y_max) < M_EPSILON)
		normal = tuple_new_vector(0, 1, 0);
	else if (distance < 1 && fabs(local_point.y - cyl->bounds.y_min) < M_EPSILON)
		normal = tuple_new_vector(0, -1, 0);
	else
		normal = tuple_new_vector(local_point.x, 0.0, local_point.z);
	normal = matrix_multiply_tuple(shape->transform.inv_tf_transpose, normal);
	normal.w = 0;
	return (tuple_normalize(normal));
}