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

	max = cube_bounds_get(1, 3, isec_point.x, isec_point.y, isec_point.z);
	if (is_approx_equal(max, isec_point.x, M_EPSILON))
		return (tuple_new_point(isec_point.x, 0, 0));
	else if (is_approx_equal(max, isec_point.y, M_EPSILON))
		return (tuple_new_point(0, isec_point.y, 0));
	else if (is_approx_equal(max, isec_point.z, M_EPSILON))
		return (tuple_new_point(0, 0, isec_point.z));
	return (tuple_point_zero());
}