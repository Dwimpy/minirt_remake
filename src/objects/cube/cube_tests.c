/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 22:25:04 by arobu             #+#    #+#             */
/*   Updated: 2023/08/11 22:25:04 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "intersect.h"
#include "tuple.h"
#include "vector.h"


static void	cube_test_intersection()
{
	t_shape cube;
	t_ray ray;
	t_vector isect;
	t_intersect *i1;
	t_intersect *i2;

	cube = shape_new_cube();
	isect = vector_init(10, sizeof(t_intersect));
	ray = ray_new(tuple_new_point(5, 0.5, 0), tuple_new_vector(-1, 0, 0));
	cube.vtable.intersect(&cube, ray, &isect);
	i1 = vector_at(&isect, 0);
	i2 = vector_at(&isect, 1);
	assert(is_approx_equal(i1->t, 4.0, M_EPSILON));
	assert(is_approx_equal(i2->t, 6.0, M_EPSILON));

	vector_clear(&isect);
	ray = ray_new(tuple_new_point(-5, 0.5, 0), tuple_new_vector(1, 0, 0));
	cube.vtable.intersect(&cube, ray, &isect);
	i1 = vector_at(&isect, 0);
	i2 = vector_at(&isect, 1);
	assert(is_approx_equal(i1->t, 4.0, M_EPSILON));
	assert(is_approx_equal(i2->t, 6.0, M_EPSILON));

	vector_clear(&isect);
	ray = ray_new(tuple_new_point(0.5, 5, 0), tuple_new_vector(0, -1, 0));
	cube.vtable.intersect(&cube, ray, &isect);
	i1 = vector_at(&isect, 0);
	i2 = vector_at(&isect, 1);
	assert(is_approx_equal(i1->t, 4.0, M_EPSILON));
	assert(is_approx_equal(i2->t, 6.0, M_EPSILON));

	vector_clear(&isect);
	ray = ray_new(tuple_new_point(0.5, -5, 0), tuple_new_vector(0, 1, 0));
	cube.vtable.intersect(&cube, ray, &isect);
	i1 = vector_at(&isect, 0);
	i2 = vector_at(&isect, 1);
	assert(is_approx_equal(i1->t, 4.0, M_EPSILON));
	assert(is_approx_equal(i2->t, 6.0, M_EPSILON));

	vector_clear(&isect);
	ray = ray_new(tuple_new_point(0.5, 0.0, 5.0), tuple_new_vector(0, 0, -1));
	cube.vtable.intersect(&cube, ray, &isect);
	i1 = vector_at(&isect, 0);
	i2 = vector_at(&isect, 1);
	assert(is_approx_equal(i1->t, 4.0, M_EPSILON));
	assert(is_approx_equal(i2->t, 6.0, M_EPSILON));

	vector_clear(&isect);
	ray = ray_new(tuple_new_point(0.5, 0.0, -5.0), tuple_new_vector(0, 0, 1));
	cube.vtable.intersect(&cube, ray, &isect);
	i1 = vector_at(&isect, 0);
	i2 = vector_at(&isect, 1);
	assert(is_approx_equal(i1->t, 4.0, M_EPSILON));
	assert(is_approx_equal(i2->t, 6.0, M_EPSILON));

	vector_clear(&isect);
	ray = ray_new(tuple_new_point(0.0, 0.5, 0.0), tuple_new_vector(0, 0, 1));
	cube.vtable.intersect(&cube, ray, &isect);
	i1 = vector_at(&isect, 0);
	i2 = vector_at(&isect, 1);
	assert(is_approx_equal(i1->t, -1.0, M_EPSILON));
	assert(is_approx_equal(i2->t, 1.0, M_EPSILON));

}

static void	cube_test_ray_misses(void)
{
	t_shape cube;
	t_ray ray;
	t_vector isect;
	t_intersect *i1;
	t_intersect *i2;

	cube = shape_new_cube();
	isect = vector_init(10, sizeof(t_intersect));
	ray = ray_new(tuple_new_point(5, 0.5, 0), tuple_new_vector(-1, 0, 0));
	cube.vtable.intersect(&cube, ray, &isect);
	i1 = vector_at(&isect, 0);
	i2 = vector_at(&isect, 1);
	assert(is_approx_equal(i1->t, 4.0, M_EPSILON));
	assert(is_approx_equal(i2->t, 6.0, M_EPSILON));

	vector_clear(&isect);
	ray = ray_new(tuple_new_point(-5, 0.5, 0), tuple_new_vector(1, 0, 0));
	cube.vtable.intersect(&cube, ray, &isect);
	i1 = vector_at(&isect, 0);
	i2 = vector_at(&isect, 1);
	assert(is_approx_equal(i1->t, 4.0, M_EPSILON));
	assert(is_approx_equal(i2->t, 6.0, M_EPSILON));

	vector_clear(&isect);
	ray = ray_new(tuple_new_point(0.5, 5, 0), tuple_new_vector(0, -1, 0));
	cube.vtable.intersect(&cube, ray, &isect);
	i1 = vector_at(&isect, 0);
	i2 = vector_at(&isect, 1);
	assert(is_approx_equal(i1->t, 4.0, M_EPSILON));
	assert(is_approx_equal(i2->t, 6.0, M_EPSILON));

	vector_clear(&isect);
	ray = ray_new(tuple_new_point(0.5, -5, 0), tuple_new_vector(0, 1, 0));
	cube.vtable.intersect(&cube, ray, &isect);
	i1 = vector_at(&isect, 0);
	i2 = vector_at(&isect, 1);
	assert(is_approx_equal(i1->t, 4.0, M_EPSILON));
	assert(is_approx_equal(i2->t, 6.0, M_EPSILON));

	vector_clear(&isect);
	ray = ray_new(tuple_new_point(0.5, 0.0, 5.0), tuple_new_vector(0, 0, -1));
	cube.vtable.intersect(&cube, ray, &isect);
	i1 = vector_at(&isect, 0);
	i2 = vector_at(&isect, 1);
	assert(is_approx_equal(i1->t, 4.0, M_EPSILON));
	assert(is_approx_equal(i2->t, 6.0, M_EPSILON));

	vector_clear(&isect);
	ray = ray_new(tuple_new_point(0.5, 0.0, -5.0), tuple_new_vector(0, 0, 1));
	cube.vtable.intersect(&cube, ray, &isect);
	i1 = vector_at(&isect, 0);
	i2 = vector_at(&isect, 1);
	assert(is_approx_equal(i1->t, 4.0, M_EPSILON));
	assert(is_approx_equal(i2->t, 6.0, M_EPSILON));

	vector_clear(&isect);
	ray = ray_new(tuple_new_point(0.0, 0.5, 0.0), tuple_new_vector(0, 0, 1));
	cube.vtable.intersect(&cube, ray, &isect);
	i1 = vector_at(&isect, 0);
	i2 = vector_at(&isect, 1);
	assert(is_approx_equal(i1->t, -1.0, M_EPSILON));
	assert(is_approx_equal(i2->t, 1.0, M_EPSILON));
}

void cube_tests(void)
{
	cube_test_intersection();
}