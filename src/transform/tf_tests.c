/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tf_tests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:56:00 by arobu             #+#    #+#             */
/*   Updated: 2023/08/09 15:56:00 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "transform.h"
#include "tuple.h"

void transform_tests()
{
	t_transform tf;
	t_transform tf2;
	t_tuple tuple;

	tf = tf_new();
	tf2 = tf_new();
	tf_scale(&tf, 2, 3, 4);
	tf_compute(&tf);
	tuple = matrix_multiply_tuple(tf.tf, tuple_new_point(-4, 6, 8));
	assert(tuple.w == 1);
	assert(tuple.x == -8);
	assert(tuple.y == 18);
	assert(tuple.z == 32);

	tuple = matrix_multiply_tuple(tf.inv_tf, tuple_new_point(-4, 6, 8));
	assert(tuple.w == 1);
	assert(tuple.x == -2);
	assert(tuple.y == 2);
	assert(tuple.z == 2);

	tuple = matrix_multiply_tuple(tf.inv_tf, tuple_new_vector(-4, 6, 8));
	assert(tuple.w == 0);
	assert(tuple.x == -2);
	assert(tuple.y == 2);
	assert(tuple.z == 2);

	tf_scale(&tf, -1, 1, 1);
	tf_compute(&tf);
	tuple = matrix_multiply_tuple(tf.tf, tuple_new_vector(2, 3, 4));
	assert(tuple.w == 0);
	assert(tuple.x == -2);
	assert(tuple.y == 3);
	assert(tuple.z == 4);

	tf_reset(&tf);
	tf_reset(&tf2);
	tf_rotate(&tf, 45, 0, 0);
	tf_rotate(&tf2, 90, 0, 0);
	tf_compute(&tf);
	tf_compute(&tf2);
	tuple = matrix_multiply_tuple(tf.tf, tuple_new_point(0, 1, 0));
	assert(tuple.w == 1);
	assert(tuple.x == 0);
	assert(is_approx_equal(tuple.y, sqrt(2) / 2, M_EPSILON));
	assert(is_approx_equal(tuple.z, sqrt(2) / 2, M_EPSILON));
	tuple = matrix_multiply_tuple(tf2.tf, tuple_new_point(0, 1, 0));
	assert(tuple.w == 1);
	assert(tuple.x == 0);
	assert(is_approx_equal(tuple.y, 0, M_EPSILON));
	assert(is_approx_equal(tuple.z, 1, M_EPSILON));

	tuple = matrix_multiply_tuple(tf.inv_tf, tuple_new_point(0, 1, 0));
	assert(tuple.w == 1);
	assert(tuple.x == 0);
	assert(is_approx_equal(tuple.y, sqrt(2) / 2, M_EPSILON));
	assert(is_approx_equal(tuple.z, -sqrt(2) / 2, M_EPSILON));

	tf_reset(&tf);
	tf_reset(&tf2);
	tf_rotate(&tf, 0, 45, 0);
	tf_rotate(&tf2, 0, 90, 0);
	tf_compute(&tf);
	tf_compute(&tf2);
	tuple = matrix_multiply_tuple(tf.tf, tuple_new_point(0, 0, 1));
	assert(tuple.w == 1);
	assert(is_approx_equal(tuple.x, sqrt(2) / 2, M_EPSILON));
	assert(tuple.y == 0);
	assert(is_approx_equal(tuple.z, sqrt(2) / 2, M_EPSILON));
	tuple = matrix_multiply_tuple(tf2.tf, tuple_new_point(0, 0, 1));
	assert(tuple.w == 1);
	assert(is_approx_equal(tuple.x, 1, M_EPSILON));
	assert(is_approx_equal(tuple.y, 0, M_EPSILON));
	assert(is_approx_equal(tuple.z, 0, M_EPSILON));

	tuple = matrix_multiply_tuple(tf.inv_tf, tuple_new_point(0, 0, 1));
	assert(is_approx_equal(tuple.w, 1, M_EPSILON));
	assert(is_approx_equal(tuple.x, -sqrt(2) / 2, M_EPSILON));
	assert(tuple.y == 0);
	assert(is_approx_equal(tuple.z, sqrt(2) / 2, M_EPSILON));

	tf_reset(&tf);
	tf_reset(&tf2);
	tf_rotate(&tf, 0, 0, 45);
	tf_rotate(&tf2, 0, 0, 90);
	tf_compute(&tf);
	tf_compute(&tf2);
	tuple = matrix_multiply_tuple(tf.tf, tuple_new_point(0, 1, 0));
	assert(tuple.w == 1);
	assert(is_approx_equal(tuple.x, -sqrt(2) / 2, M_EPSILON));
	assert(is_approx_equal(tuple.y, sqrt(2) / 2, M_EPSILON));
	assert(tuple.z == 0);
	tuple = matrix_multiply_tuple(tf2.tf, tuple_new_point(0, 1, 0));
	assert(is_approx_equal(tuple.w, 1, M_EPSILON));
	assert(is_approx_equal(tuple.x, -1, M_EPSILON));
	assert(is_approx_equal(tuple.y, 0, M_EPSILON));
	assert(is_approx_equal(tuple.z, 0, M_EPSILON));
//
//	tf = tf_shear(1, 0, 0, 0, 0, 0);
//	tuple = matrix_multiply_tuple(tf.tf, tuple_new_point(2, 3, 4));
//	assert(tuple.w == 1);
//	assert(tuple.x == 5);
//	assert(tuple.y == 3);
//	assert(tuple.z == 4);
//
//	tf = tf_shear(0, 1, 0, 0, 0, 0);
//	tuple = matrix_multiply_tuple(tf.tf, tuple_new_point(2, 3, 4));
//	assert(tuple.w == 1);
//	assert(tuple.x == 6);
//	assert(tuple.y == 3);
//	assert(tuple.z == 4);
//
//	tf = tf_shear(0, 0, 1, 0, 0, 0);
//	tuple = matrix_multiply_tuple(tf.tf, tuple_new_point(2, 3, 4));
//	assert(tuple.w == 1);
//	assert(tuple.x == 2);
//	assert(tuple.y == 5);
//	assert(tuple.z == 4);
//
//	tf = tf_shear(0, 0, 0, 1, 0, 0);
//	tuple = matrix_multiply_tuple(tf.tf, tuple_new_point(2, 3, 4));
//	assert(tuple.w == 1);
//	assert(tuple.x == 2);
//	assert(tuple.y == 7);
//	assert(tuple.z == 4);
//
//	tf = tf_shear(0, 0, 0, 0, 1, 0);
//	tuple = matrix_multiply_tuple(tf.tf, tuple_new_point(2, 3, 4));
//	assert(tuple.w == 1);
//	assert(tuple.x == 2);
//	assert(tuple.y == 3);
//	assert(tuple.z == 6);
//
//	tf = tf_shear(0, 0, 0, 0, 0, 1);
//	tuple = matrix_multiply_tuple(tf.tf, tuple_new_point(2, 3, 4));
//	assert(tuple.w == 1);
//	assert(tuple.x == 2);
//	assert(tuple.y == 3);
//	assert(tuple.z == 7);
	tf_reset(&tf);
	tf_rotate(&tf, 90, 0, 0);
	tf_scale(&tf, 5, 5, 5);
	tf_translate(&tf, 10, 5, 7);
	tf_compute(&tf);
	tuple = matrix_multiply_tuple(tf.tf, tuple_new_point(1, 0, 1));
	tuple_print(tuple);
	assert(is_approx_equal(tuple.w, 1, M_EPSILON));
	assert(is_approx_equal(tuple.x, 15, M_EPSILON));
	assert(is_approx_equal(tuple.y, 0, M_EPSILON));
	assert(is_approx_equal(tuple.z, 7, M_EPSILON));
}