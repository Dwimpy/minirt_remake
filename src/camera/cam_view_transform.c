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

static void	camera_vt_set_elements(t_transform *tf, t_tuple left, t_tuple up, t_tuple forward);

t_transform	camera_view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_onb		onb;
	t_transform	view_transform;
	t_transform	translate;
	double		**ptr;

	view_transform = tf_new();
	onb.forward = tuple_normalize(tuple_subtract(to, from));
	onb.left = tuple_cross(onb.forward, tuple_normalize(up));
	onb.up = tuple_cross(onb.left, onb.forward);
	translate = tf_translate(-from.x, -from.y, -from.z);
	camera_vt_set_elements(&view_transform, onb.left, onb.up, onb.forward);
	ptr = view_transform.tf.data;
	view_transform.tf = matrix_multiply(view_transform.tf, translate.tf);
	view_transform.inv_tf = matrix_inverse(view_transform.tf);
	view_transform.tf_transpose = matrix_transpose(view_transform.tf);
	view_transform.inv_tf_transpose = matrix_transpose(view_transform.inv_tf);
	free(ptr);
	tf_free(translate);
	return (view_transform);
}

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
