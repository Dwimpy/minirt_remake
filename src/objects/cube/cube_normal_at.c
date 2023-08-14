/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_normal_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:45:59 by arobu             #+#    #+#             */
/*   Updated: 2023/08/11 21:45:59 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "tuple.h"

t_tuple	cube_normal_at(t_shape *shape, t_tuple isec_point)
{
	double	max;
	t_tuple	local_point;
	double	abs_x;
	double	abs_y;
	double	abs_z;

	local_point = matrix_multiply_tuple(shape->transform.inv_tf, isec_point);
	abs_x = fabs(local_point.x);
	abs_y = fabs(local_point.y);
	abs_z = fabs(local_point.z);
	max = cube_bounds_get(1, 3, abs_x, abs_y, abs_z);
	if (is_approx_equal(max, abs_x, M_EPSILON))
		return (tuple_normalize(tuple_new_vector(local_point.x, 0, 0)));
	else if (is_approx_equal(max, abs_y, M_EPSILON))
		return (tuple_normalize(tuple_new_vector(0, local_point.y, 0)));
	else if (is_approx_equal(max, abs_z, M_EPSILON))
		return (tuple_normalize(tuple_new_vector(0, 0, local_point.z)));
	return (tuple_vector_zero());
}