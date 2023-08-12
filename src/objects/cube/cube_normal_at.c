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
	double	absx;
	double	absy;
	double	absz;

	local_point = matrix_multiply_tuple(shape->transform.inv_tf, isec_point);
	absx = fabs(local_point.x);
	absy = fabs(local_point.y);
	absz = fabs(local_point.z);
	max = cube_bounds_get(1, 3, absx, absy, absz);
	if (is_approx_equal(max, absx, M_EPSILON))
		return (tuple_new_vector(local_point.x, 0, 0));
	else if (is_approx_equal(max, absy, M_EPSILON))
		return (tuple_new_vector(0, local_point.y, 0));
	else if (is_approx_equal(max, absz, M_EPSILON))
		return (tuple_new_vector(0, 0, local_point.z));
}