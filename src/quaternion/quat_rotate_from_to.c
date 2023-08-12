/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_rotate_from_to.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 00:01:23 by arobu             #+#    #+#             */
/*   Updated: 2023/08/13 00:01:23 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"

t_quaternion	quat_rotate_from_to(t_tuple from, t_tuple to)
{
	t_quaternion	rot_quat;
	t_tuple			axis;
	t_real			angle;
	t_real 			sin_half_angle;

	axis = tuple_normalize(tuple_cross(from, to));
	angle = acos(tuple_dot(from, to));
	rot_quat.w = cos(angle / 2.0);
	sin_half_angle = sin(angle / 2.0);
	return (quaternion_new(axis.x * sin_half_angle, \
					axis.y * sin_half_angle, \
					axis.z * sin_half_angle, 1));
}