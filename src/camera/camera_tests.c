/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:35:00 by arobu             #+#    #+#             */
/*   Updated: 2023/08/09 21:35:00 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "matrix.h"
#include "ray.h"
#include "transform.h"
#include "tuple.h"

void camera_tests(void)
{
	t_transform t;
	t_matrix res;
	t_camera camera;
	t = camera_view_transform(tuple_new_point(0, 0, 0), tuple_new_point(0, 0, 1), tuple_new_vector(0, 1, 0));
	assert(matrix_equal(t.tf, tf_scale(-1, 1, -1).tf));

	t = camera_view_transform(tuple_new_point(0, 0, 8), tuple_new_point(0, 0, 0), tuple_new_vector(0, 1, 0));
	assert(matrix_equal(t.tf, tf_translate(0, 0, -8).tf));

	t = camera_view_transform(tuple_new_point(1, 3, 2), tuple_new_point(4, -2, 8), tuple_new_vector(1, 1, 0));
	res = matrix_init(4, 4);
	matrix_set(res, 0, 0, -0.50709);
	matrix_set(res, 0, 1, 0.50709);
	matrix_set(res, 0, 2, 0.67612);
	matrix_set(res, 0, 3, -2.36643);

	matrix_set(res, 1, 0, 0.76772);
	matrix_set(res, 1, 1, 0.60609);
	matrix_set(res, 1, 2, 0.12122);
	matrix_set(res, 1, 3, -2.82843);

	matrix_set(res, 2, 0, -0.35857);
	matrix_set(res, 2, 1, 0.59761);
	matrix_set(res, 2, 2, -0.71714);
	matrix_set(res, 2, 3, 0.00000);

	matrix_set(res, 3, 0, 0.00000);
	matrix_set(res, 3, 1, 0.00000);
	matrix_set(res, 3, 2, 0.00000);
	matrix_set(res, 3, 3, 1.00000);
	assert(matrix_equal(t.tf, res));

	camera = camera_new(160, 120, 90);
	assert(camera.width == 160);
	assert(camera.height == 120);
	assert(camera.fov == M_PI_2);
	assert(matrix_equal(camera.tf.tf, matrix_identity()));

	camera = camera_new(200, 125, 90);
	assert(is_approx_equal(camera.pixel_size, 0.01, M_EPSILON));

	camera = camera_new(125, 200, 90);
	assert(is_approx_equal(camera.pixel_size, 0.01, M_EPSILON));

	t_ray ray;
	camera = camera_new(201, 101, 90);
	ray = camera_get_ray(&camera, 100, 50);
	assert(tuple_equal(ray.origin, tuple_new_point(0, 0, 0)));
	assert(tuple_equal(ray.direction, tuple_new_vector(0, 0, -1)));

	ray = camera_get_ray(&camera, 0, 0);
	assert(tuple_equal(ray.origin, tuple_new_point(0, 0, 0)));
	assert(tuple_equal(ray.direction, tuple_new_vector(0.66519, 0.33259, -0.66851)));

	camera_set_view_transform(&camera, \
        tf_translate(0, -2, 5));
	ray = ray_new(tuple_new_point(0, 0, 0), tuple_new_vector(sqrt(2) / 2, sqrt(2)/ 2, 0));
	ray.origin = matrix_multiply_tuple(camera.tf.inv_tf, ray.origin);
	matrix_print(camera.tf.inv_tf);
	tuple_print(ray.origin);
	ray = camera_get_ray(&camera, 0, 0);
	tuple_print(ray.origin);
	tuple_print(ray.direction);
	assert(tuple_equal(ray.origin, tuple_new_point(0, 2, -5)));
	assert(tuple_equal(ray.direction, tuple_new_vector(sqrt(2) / 2, 0, -sqrt(2) / 2)));
}