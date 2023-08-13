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

inline static t_tuple	handle_zero_case(t_tuple to, t_tuple from);
static void	camera_vt_set_elements(t_transform *tf, t_tuple left, t_tuple up, t_tuple forward);


t_transform camera_view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_onb			onb;
	t_tuple			from_to_vector;
	t_tuple			upn;
	t_transform		view_transform;
	t_transform		translation;

	from_to_vector = tuple_subtract(to, from);
	onb.forward = tuple_normalize(tuple_subtract(to, from));
	upn = tuple_normalize(up);
	onb.left = tuple_normalize(tuple_cross(onb.forward, upn));
	onb.up = tuple_cross(onb.left, onb.forward);
	tuple_print(onb.up);
	tuple_print(onb.left);
	view_transform = tf_new();
	camera_vt_set_elements(&view_transform, onb.left, onb.up, onb.forward);
	translation = tf_translate(-from.x, -from.y, -from.z);
	view_transform.tf = matrix_multiply(view_transform.tf, translation.tf);
	view_transform.inv_tf = matrix_inverse(view_transform.tf);
	view_transform.tf_transpose = matrix_transpose(view_transform.tf);
	view_transform.inv_tf_transpose = matrix_transpose(view_transform.inv_tf);
	tf_free(translation);
	return (view_transform);
}

inline static void	\
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

inline static t_tuple	handle_zero_case(t_tuple to, t_tuple from)
{
	t_tuple	from_to_vector;

	from_to_vector = tuple_subtract(to, from);
	if (is_approx_equal(from_to_vector.z, 0.0, M_EPSILON))
		from_to_vector.z += M_EPSILON;
	if (is_approx_equal(from_to_vector.y, 0.0, M_EPSILON))
		from_to_vector.y += M_EPSILON;
	if (is_approx_equal(from_to_vector.x, 0.0, M_EPSILON))
		from_to_vector.x += M_EPSILON;
	return (from_to_vector);
}