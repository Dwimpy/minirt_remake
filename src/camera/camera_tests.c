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
#include "color.h"
#include "intersect.h"
#include "matrix.h"
#include "ray.h"
#include "transform.h"
#include "tuple.h"
#include "scene.h"

void camera_tests(void)
{
	t_matrix res;
	t_camera camera;
	t_scene	world;
	t_transform test;
	camera = camera_new(1024, 1024, 60);

	test = tf_new();
	camera_view_transform(&camera, tuple_new_point(0, 0, 0), tuple_new_point(0, 0, 1), tuple_new_vector(0, 1, 0));
	tf_scale(&test, -1, 1, -1);
	tf_scale(&camera.tf, -1, 1, -1);
	assert(matrix_equal(camera.tf.scaling, test.scaling));

	tf_reset(&camera.tf);
	tf_translate(&test, 0, 0, -8);
	camera_view_transform(&camera, tuple_new_point(0, 0, 8), tuple_new_point(0, 0, 0), tuple_new_vector(0, 1, 0));
	assert(matrix_equal(camera.tf.tf, test.translation));

	tf_reset(&camera.tf);
	camera_view_transform(&camera, tuple_new_point(1, 3, 2), tuple_new_point(4, -2, 8), tuple_new_vector(1, 1, 0));
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
	assert(matrix_equal(camera.tf.tf, res));

	camera_set_params(&camera, 160, 120, 90);
	assert(camera.width == 160);
	assert(camera.height == 120);
	assert(camera.fov == M_PI_2);
	matrix_identity(&res);
	assert(matrix_equal(camera.tf.tf, res));

	camera_set_params(&camera, 200, 125, 90);
	assert(is_approx_equal(camera.pixel_size, 0.01, M_EPSILON));

	camera_set_params(&camera, 125, 200, 90);
	assert(is_approx_equal(camera.pixel_size, 0.01, M_EPSILON));

	t_ray ray;
	camera_set_params(&camera, 201, 101, 90);
	ray = camera_get_ray(&camera, 100, 50);
	assert(tuple_equal(ray.origin, tuple_new_point(0, 0, 0)));
	assert(tuple_equal(ray.direction, tuple_new_vector(0, 0, -1)));

	ray = camera_get_ray(&camera, 0, 0);
	assert(tuple_equal(ray.origin, tuple_new_point(0, 0, 0)));
	assert(tuple_equal(ray.direction, tuple_new_vector(0.66519, 0.33259, -0.66851)));

	camera_tf_reset(&camera);
	tf_rotate_y(&camera.tf, 45);
	tf_translate(&camera.tf, 0, -2, 5);
	camera_tf_compute(&camera);
	ray = camera_get_ray(&camera, 100, 50);
	assert(tuple_equal_p(ray.origin, tuple_new_point(0, 2, -5), M_EPSILON * 100));
	assert(tuple_equal_p(ray.direction, tuple_new_vector(sqrt(2) / 2, 0, -sqrt(2) / 2), M_EPSILON * 10));

	t_color	color;

	world = scene_default();
	camera = camera_new(11, 11, 90);
	camera_view_transform(&camera, \
				tuple_new_point(0, 0, -5), \
					tuple_new_point(0, 0, 0), \
						tuple_new_vector(0, 1, 0));
	ray = camera_get_ray(&camera, 5, 5);
	color = intersect_color_at(&world, &ray, 1);
	assert(tuple_equal(color, tuple_new_vector(0.38066, 0.47583, 0.2855)));
}