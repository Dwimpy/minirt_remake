/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_rotate_vector.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 22:26:40 by arobu             #+#    #+#             */
/*   Updated: 2023/08/12 22:26:40 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"

t_tuple	quat_rotate_vector(t_tuple v, t_quaternion q)
{
	t_quaternion	q_vector;
	t_quaternion	rotate_quat;
	t_tuple			rotated_vector;

	q_vector = quaternion_new(v.x, v.y, v.z, 0.0);
	rotate_quat = quat_multiply(q, q_vector);
	rotate_quat = quat_multiply(rotate_quat, quat_conjugate(q));
	rotated_vector = tuple_new_vector(\
		rotate_quat.x, rotate_quat.y, rotate_quat.z);
	return (rotated_vector);
}
