/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_view_transform.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:40:47 by arobu             #+#    #+#             */
/*   Updated: 2023/08/08 03:57:02 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "matrix.h"
#include "onb.h"
#include "transform.h"
#include "tuple.h"
#include "quaternion.h"

static void	camera_vt_set_elements(t_transform *tf, t_tuple left, t_tuple up, t_tuple forward);

t_quaternion quaternion_rotate_from_to(t_tuple from, t_tuple to)
{
    t_tuple axis = tuple_normalize(tuple_cross(from, to));
    t_real angle = acos(tuple_dot(from, to));

    // Convert axis-angle representation to quaternion
    t_quaternion rotation_quat;
    rotation_quat.w = cos(angle / 2.0);
    t_real sin_half_angle = sin(angle / 2.0);
    rotation_quat.x = axis.x * sin_half_angle;
    rotation_quat.y = axis.y * sin_half_angle;
    rotation_quat.z = axis.z * sin_half_angle;

    return rotation_quat;
}

//
//t_transform	camera_view_transform(t_tuple from, t_tuple to, t_tuple up)
//{
//	t_onb		onb;
//	t_transform	view_transform;
//	t_transform	translate;
//	t_real		**ptr;
//	t_quaternion q;
//
//	view_transform = tf_new();
//	onb.forward = tuple_normalize(tuple_subtract(to, from));
//	tuple_print(onb.forward);
//	onb.left = tuple_cross(onb.forward, tuple_normalize(up));
//	onb.up = tuple_cross(onb.left, onb.forward);
//	translate = tf_translate(-from.x, -from.y, -from.z);
//	camera_vt_set_elements(&view_transform, onb.left, onb.up, onb.forward);
//	ptr = view_transform.tf.data;
//	view_transform.tf = matrix_multiply(view_transform.tf, translate.tf);
//	view_transform.inv_tf = matrix_inverse(view_transform.tf);
//	free(ptr);
//	tf_free(translate);
//	return (view_transform);
//}

static void	\
	camera_vt_set_elements(\
		t_transform *tf, t_tuple left, t_tuple up, t_tuple forward)
{
	matrix_set(tf->tf, 0, 0, left.x);
	matrix_set(tf->tf, 0, 1, left.y);
	matrix_set(tf->tf, 0, 2, left.z);
	matrix_set(tf->tf, 1, 0, up.x);
	matrix_set(tf->tf, 1, 1, up.y);
	matrix_set(tf->tf, 1, 2, up.z);
	matrix_set(tf->tf, 2, 0, -forward.x);
	matrix_set(tf->tf, 2, 1, -forward.y);
	matrix_set(tf->tf, 2, 2, -forward.z);
}
//
//


t_transform camera_view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_onb	onb;
	t_quaternion rotation_quat;

	onb.forward = tuple_normalize(tuple_subtract(from, to));
	onb.left = tuple_normalize(tuple_cross(up, onb.forward));
    onb.up = tuple_cross(onb.forward, onb.left);


	rotation_quat = quaternion_rotate_from_to(tuple_new_vector(0, 1, 0), onb.up);

    // Transform up vector using rotation quaternion
    t_tuple rotated_up = quat_rotate_vector(up, rotation_quat);

    // Create LookAt matrix
    t_transform look_at_transform = tf_new();
    camera_vt_set_elements(&look_at_transform, onb.left, rotated_up, tuple_negate(onb.forward)); // Negate forward for left-handed system

    // Apply translation to the LookAt matrix
    t_transform translation_matrix = tf_translate(-from.x, -from.y, -from.z);
    look_at_transform.tf = matrix_multiply(look_at_transform.tf, translation_matrix.tf);

    // Update inverse transformations
    look_at_transform.inv_tf = matrix_inverse(look_at_transform.tf);
    look_at_transform.tf_transpose = matrix_transpose(look_at_transform.tf);
    look_at_transform.inv_tf_transpose = matrix_transpose(look_at_transform.inv_tf);

    return look_at_transform;
}