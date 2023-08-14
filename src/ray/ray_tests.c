/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:22:03 by arobu             #+#    #+#             */
/*   Updated: 2023/08/09 16:22:03 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "transform.h"
#include "tuple.h"

void ray_tests()
{
	t_ray ray;
	t_tuple point;
	t_transform	tf;

	tf = tf_new();
	ray = ray_new(tuple_new_point(1, 2, 3), tuple_new_vector(4, 5, 6));
	assert(ray.origin.w == 1);
	assert(ray.origin.x == 1);
	assert(ray.origin.y == 2);
	assert(ray.origin.z == 3);
	assert(ray.direction.w == 0);
	assert(ray.direction.x == 4);
	assert(ray.direction.y == 5);
	assert(ray.direction.z == 6);

	ray = ray_new(tuple_new_point(2, 3, 4), tuple_new_vector(1, 0, 0));
	point = ray_at(ray, 0);
	assert(point.w == 1);
	assert(point.x == 2);
	assert(point.y == 3);
	assert(point.z == 4);

	point = ray_at(ray, 1);
	assert(point.w == 1);
	assert(point.x == 3);
	assert(point.y == 3);
	assert(point.z == 4);

	point = ray_at(ray, -1);
	assert(point.w == 1);
	assert(point.x == 1);
	assert(point.y == 3);
	assert(point.z == 4);

	point = ray_at(ray, 2.5);
	assert(point.w == 1);
	assert(is_approx_equal(point.x, 4.5, M_EPSILON));
	assert(point.y == 3);
	assert(point.z == 4);

	ray = ray_new(tuple_new_point(1, 2, 3), tuple_new_vector(0, 1, 0));
	tf_reset(&tf);
	tf_translate(&tf, 3, 4, 5);
	tf_compute(&tf);
	ray = ray_to_world_space(&ray, tf);
	assert(ray.origin.w == 1);
	assert(ray.origin.x == 4);
	assert(ray.origin.y == 6);
	assert(ray.origin.z == 8);
	assert(ray.direction.w == 0);
	assert(ray.direction.x == 0);
	assert(ray.direction.y == 1);
	assert(ray.direction.z == 0);

	tf_reset(&tf);
	tf_scale(&tf, 2, 3, 4);
	tf_compute(&tf);
	ray = ray_new(tuple_new_point(1, 2, 3), tuple_new_vector(0, 1, 0));
	ray = ray_to_world_space(&ray, tf);
	assert(ray.origin.w == 1);
	assert(ray.origin.x == 2);
	assert(ray.origin.y == 6);
	assert(ray.origin.z == 12);
	assert(ray.direction.w == 0);
	assert(ray.direction.x == 0);
	assert(ray.direction.y == 3);
	assert(ray.direction.z == 0);
	tf_free(tf);
}