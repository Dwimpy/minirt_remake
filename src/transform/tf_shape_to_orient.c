/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tf_orientation_to_rotation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:39:34 by arobu             #+#    #+#             */
/*   Updated: 2023/08/07 19:39:34 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "quaternion.h"
#include "transform.h"
#include "tuple.h"

t_transform	tf_shape_to_orientation(t_tuple to)
{
	t_transform		tf;
	t_quaternion	q;

	to.z *= -1;
	q = quat_rot_from_to(tuple_new_vector(0, 1, 0), to);
	tf.tf = quat_to_matrix(q);
	return (tf);
}
