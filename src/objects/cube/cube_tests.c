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


	vector_clear(&isect);
	ray = ray_new(tuple_new_point(-2.0, 0.0, 0.0), tuple_new_vector(0.2673, 0.5345, 0.8018));
	cube.vtable.intersect(&cube, ray, &isect);
	assert(isect.size == 0);

	vector_clear(&isect);
	ray = ray_new(tuple_new_point(0.0, -2.0, 0.0), tuple_new_vector(0.8018, 0.2673, 0.5345));
	cube.vtable.intersect(&cube, ray, &isect);
	assert(isect.size == 0);

	vector_clear(&isect);
	ray = ray_new(tuple_new_point(0.0, 0.0, -2.0), tuple_new_vector(0.5345, 0.8018, 0.2673));
	cube.vtable.intersect(&cube, ray, &isect);
	assert(isect.size == 0);

	vector_clear(&isect);
	ray = ray_new(tuple_new_point(2.0, 0.0, 2.0), tuple_new_vector(0, 0, -1));
	cube.vtable.intersect(&cube, ray, &isect);
	assert(isect.size == 0);

	vector_clear(&isect);
	ray = ray_new(tuple_new_point(0.0, 2.0, 2.0), tuple_new_vector(0, -1, 0));
	cube.vtable.intersect(&cube, ray, &isect);
	assert(isect.size == 0);

	vector_clear(&isect);
	ray = ray_new(tuple_new_point(2.0, 2.0, 0.0), tuple_new_vector(-1, 0, 0));
	cube.vtable.intersect(&cube, ray, &isect);
	assert(isect.size == 0);
}
//
//| origin
//| point(-2, 0, 0) | point(0, -2, 0) | point(0, 0, -2) | point(2, 0, 2) | point(0, 2, 2) | point(2, 2, 0)
//| vector(0.2673, 0.5345, 0.8018) |
//| vector(0.8018, 0.2673, 0.5345) |
//| vector(0.5345, 0.8018, 0.2673) |
//| vector(0, 0, -1) |
//| vector(0, -1, 0) |
//| vector(-1, 0, 0) |

void	cube_test_normals(void)
{
	t_shape cube;
	t_ray ray;
	t_tuple normal;


	cube = shape_new_cube();
	normal = cube.vtable.normal_at(&cube, tuple_new_point(1, 0.5, -0.8));
	tuple_print(normal);
	normal = cube.vtable.normal_at(&cube, tuple_new_point(-1, -0.2, 0.9));
	tuple_print(normal);
	normal = cube.vtable.normal_at(&cube, tuple_new_point(0.4, 1, -0.1));
	tuple_print(normal);
	normal = cube.vtable.normal_at(&cube, tuple_new_point(0.3, -1, -0.7));
	tuple_print(normal);
	normal = cube.vtable.normal_at(&cube, tuple_new_point(-0.6, 0.3, 1));
	tuple_print(normal);
	normal = cube.vtable.normal_at(&cube, tuple_new_point(0.4, 0.4, -1));
	tuple_print(normal);
	normal = cube.vtable.normal_at(&cube, tuple_new_point(1, 1, 1));
	tuple_print(normal);
	normal = cube.vtable.normal_at(&cube, tuple_new_point(-1, -1, -1));
	tuple_print(normal);
}

void	cube_tests(void)
{
	cube_test_intersection();
	cube_test_ray_misses();
	cube_test_normals();
}