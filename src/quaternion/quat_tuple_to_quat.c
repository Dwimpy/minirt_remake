/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_tuple_to_quat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:03:19 by arobu             #+#    #+#             */
/*   Updated: 2023/08/07 22:03:19 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"
#include "tuple.h"

t_quaternion	quat_rot_from_to(t_tuple from, t_tuple to)
{
	t_tuple	cross;
	double	dot_product;
	double	magnitude;
	double	w;

	cross = tuple_cross(from, to);
	dot_product = tuple_dot(from, to);
	magnitude = tuple_magnitude(cross);
	w = sqrt((from.x * from.x + from.y * from.y + from.z * from.z) * \
		(to.x * to.x + to.y * to.y + to.z * to.z)) + dot_product;
	if (magnitude < M_EPSILON)
		return (quaternion_new(1.0, 0.0, 0.0, w));
	return (quaternion_new(\
		cross.x / magnitude, cross.y / magnitude, cross.z / magnitude, w));
}
