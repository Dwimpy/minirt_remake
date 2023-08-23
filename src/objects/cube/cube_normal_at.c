/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_normal_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:45:59 by arobu             #+#    #+#             */
/*   Updated: 2023/08/23 16:31:38 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_tuple	cube_normal_at(t_shape *shape, t_tuple isec_point)
{
	t_cube_computation	comp;

	comp.local_point = matrix_multiply_tuple(\
		shape->transform.inv_tf, isec_point);
	comp.abs_x = fabs(comp.local_point.x);
	comp.abs_y = fabs(comp.local_point.y);
	comp.abs_z = fabs(comp.local_point.z);
	comp.max = cube_bounds_get_max(3, comp.abs_x, comp.abs_y, comp.abs_z);
	comp.normal = tuple_vector_zero();
	if (is_approx_equal(comp.max, comp.abs_x, M_EPSILON))
		comp.normal = tuple_new_vector(comp.local_point.x, 0, 0);
	else if (is_approx_equal(comp.max, comp.abs_y, M_EPSILON))
		comp.normal = tuple_new_vector(0, comp.local_point.y, 0);
	else if (is_approx_equal(comp.max, comp.abs_z, M_EPSILON))
		comp.normal = tuple_new_vector(0, 0, comp.local_point.z);
	comp.world_normal = tuple_normalize(\
		matrix_multiply_tuple(shape->transform.tf, comp.normal));
	comp.world_normal.w = 0;
	return (comp.world_normal);
}
