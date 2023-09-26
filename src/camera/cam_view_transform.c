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

static t_real max(t_real a, t_real b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	camera_view_transform(t_camera *camera, t_tuple from, t_tuple to)
{
	t_onb			onb;
	t_transform		translation;

	translation = tf_new();
	from.z = max(1, from.z);
	onb.forward = tuple_normalize(tuple_subtract(to, from));
	onb.left = tuple_cross(onb.forward, tuple_new_vector(0, 1, 0));
	onb.up = tuple_cross(onb.left, onb.forward);
	camera->onb.up = onb.up;
	camera->onb.left = onb.left;
	camera->onb.forward = onb.forward;
	camera_vt_set_elements(\
		&camera->tf, camera->onb.left, camera->onb.up, camera->onb.forward);
	tf_translate(&translation, -from.x, -from.y, -from.z);
	matrix_multiply(&camera->tf.tf, &camera->tf.tf, &translation.translation);
	matrix_inverse(&camera->tf.inv_tf, &camera->tf.tf);
	matrix_transpose(&camera->tf.inv_tf_transpose, &camera->tf.inv_tf);
	tf_free(translation);
}

inline void	\
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
