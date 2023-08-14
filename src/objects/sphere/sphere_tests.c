/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:09:30 by arobu             #+#    #+#             */
/*   Updated: 2023/08/09 17:09:49 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "intersect.h"
#include "material.h"
#include "matrix.h"
#include "ray.h"
#include "shape.h"
#include "sphere.h"
#include "transform.h"
#include "tuple.h"
#include "vector.h"
#include "light.h"

void sphere_tests(void)
{
	t_shape sphere;
	t_shape sphere2;
	t_intersect i1;
	t_intersect i2;
	t_intersect *i;
	t_vector xs;
	t_ray ray;
	t_tuple normal;

	xs = vector_init(10, sizeof(t_intersect));
	sphere = shape_new_sphere();
	sphere2 = shape_new_sphere();
	i1 = intersection(1, &sphere);
	i2 = intersection(2, &sphere);
	vector_pushback(&xs, &i1);
	vector_pushback(&xs, &i2);
	i = vector_at(&xs, 0);
	assert(i->t == 1);
	i = vector_at(&xs, 1);
	assert(i->t == 2);

	vector_clear(&xs);
	ray = ray_new(tuple_new_point(0, 0, -5), tuple_new_vector(0, 0, 1));
	sphere.vtable.intersect(&sphere, ray, &xs);
	i = vector_at(&xs, 0);
	assert(i->obj == &sphere);
	i = vector_at(&xs, 1);
	assert(i->obj == &sphere);
	assert(xs.size == 2);

	vector_clear(&xs);
	i1 = intersection(1, &sphere);
	i2 = intersection(2, &sphere);
	vector_pushback(&xs, &i1);
	vector_pushback(&xs, &i2);
	i = intersect_hit(&xs);
	assert(i->t == 1);

	vector_clear(&xs);
	i1 = intersection(-1, &sphere);
	i2 = intersection(1, &sphere);
	vector_pushback(&xs, &i1);
	vector_pushback(&xs, &i2);
	i = intersect_hit(&xs);
	assert(i->t == 1);

	vector_clear(&xs);
	i1 = intersection(-2, &sphere);
	i2 = intersection(1, &sphere);
	vector_pushback(&xs, &i1);
	vector_pushback(&xs, &i2);
	i = intersect_hit(&xs);
	assert(i->t == 1);

	vector_clear(&xs);
	i1 = intersection(5, &sphere);
	vector_pushback_intersect(&xs, i1.t, i1.obj);
	i1 = intersection(7, &sphere);
	vector_pushback_intersect(&xs, i1.t, i1.obj);
	i1 = intersection(-3, &sphere);
	vector_pushback_intersect(&xs, i1.t, i1.obj);
	i1 = intersection(2, &sphere);
	vector_pushback_intersect(&xs, i1.t, i1.obj);
	i = intersect_hit(&xs);
	assert(i->t == 2);

	vector_clear(&xs);
	ray = ray_new(tuple_new_point(0, 0, -5), tuple_new_vector(0, 0, 1));
	shape_scale(&sphere, 2, 2, 2);
	tf_compute(&sphere.transform);
	sphere.vtable.intersect(&sphere, ray, &xs);
	i = vector_at(&xs, 0);
	assert(i->t == 3);
	i = vector_at(&xs, 1);
	assert(i->t == 7);
	assert(xs.size == 2);

	vector_clear(&xs);
	shape_reset(&sphere);
	ray = ray_new(tuple_new_point(0, 0, -5), tuple_new_vector(0, 0, 1));
	shape_translate(&sphere, 5, 0, 0);
	tf_compute(&sphere.transform);
	sphere.vtable.intersect(&sphere, ray, &xs);
	assert(xs.size == 0);

	shape_reset(&sphere);
	tf_compute(&sphere.transform);
	normal = sphere.vtable.normal_at(&sphere, tuple_new_point(1, 0, 0));
	assert(is_approx_equal(normal.x, 1, M_EPSILON));
	assert(normal.y == 0);
	assert(normal.z == 0);

	normal = sphere.vtable.normal_at(&sphere, tuple_new_point(0, 1, 0));
	assert(is_approx_equal(normal.x, 0, M_EPSILON));
	assert(is_approx_equal(normal.y, 1, M_EPSILON));
	assert(is_approx_equal(normal.z, 0, M_EPSILON));

	normal = sphere.vtable.normal_at(&sphere, tuple_new_point(0, 0, 1));
	assert(is_approx_equal(normal.x, 0, M_EPSILON));
	assert(is_approx_equal(normal.y, 0, M_EPSILON));
	assert(is_approx_equal(normal.z, 1, M_EPSILON));

	normal = sphere.vtable.normal_at(&sphere, tuple_new_point(sqrt(3) / 3, sqrt(3) / 3, sqrt(3) / 3));
	assert(is_approx_equal(normal.x, sqrt(3) / 3, M_EPSILON));
	assert(is_approx_equal(normal.y, sqrt(3) / 3, M_EPSILON));
	assert(is_approx_equal(normal.z, sqrt(3) / 3, M_EPSILON));

	shape_reset(&sphere);
	shape_translate(&sphere, 0, 1, 0);
	tf_compute(&sphere.transform);
	normal = sphere.vtable.normal_at(&sphere, tuple_new_point(0, 1.70711, -0.70711));
	assert(is_approx_equal(normal.x, 0, M_EPSILON));
	assert(is_approx_equal(normal.y, 0.70711, M_EPSILON));
	assert(is_approx_equal(normal.z, -0.70711, M_EPSILON));

	shape_reset(&sphere);
	shape_scale(&sphere, 1, 0.5, 1);
	shape_rotate_z(&sphere, 36);
	tf_compute(&sphere.transform);
	normal = sphere.vtable.normal_at(&sphere, tuple_new_point(0, sqrt(2) / 2, -sqrt(2) / 2));
	assert(is_approx_equal(normal.x, 0, M_EPSILON));
	assert(is_approx_equal(normal.y, 0.97014, M_EPSILON));
	assert(is_approx_equal(normal.z, -0.24254, M_EPSILON));

	t_shape s;
	t_tuple p;
	t_tuple eyev;
	t_tuple normalv;
	t_light light;
	t_color result;

	p = tuple_new_point(0, 0, 0);
	s = shape_new_sphere();
	s.material = material_default(color_new(1, 1, 1));
	light.origin = tuple_new_point(0, 0, -10);
	light.intensity = color_new(1, 1, 1);
	eyev = tuple_new_vector(0, 0, -1);
	normalv = tuple_new_vector(0, 0, -1);
	result = light_tests(&s.material, &light, p, eyev, normalv);
	tuple_print(result);
	assert(is_approx_equal(result.x, 1.9, M_EPSILON));
	assert(is_approx_equal(result.y, 1.9, M_EPSILON));
	assert(is_approx_equal(result.z, 1.9, M_EPSILON));

	light.origin = tuple_new_point(0, 10, -10);
	light.intensity = color_new(1, 1, 1);
	eyev = tuple_new_vector(0, 0, -1);
	normalv = tuple_new_vector(0, 0, -1);
	result = light_tests(&s.material, &light, p, eyev, normalv);
	assert(is_approx_equal(result.x, 0.7364, M_EPSILON));
	assert(is_approx_equal(result.y, 0.7364, M_EPSILON));
	assert(is_approx_equal(result.z, 0.7364, M_EPSILON));

	light.origin = tuple_new_point(0, 10, -10);
	light.intensity = color_new(1, 1, 1);
	eyev = tuple_new_vector(0, -sqrt(2) / 2, -sqrt(2) / 2);
	normalv = tuple_new_vector(0, 0, -1);
	result = light_tests(&s.material, &light, p, eyev, normalv);
	assert(is_approx_equal(result.x, 1.6364, M_EPSILON));
	assert(is_approx_equal(result.y, 1.6364, M_EPSILON));
	assert(is_approx_equal(result.z, 1.6364, M_EPSILON));

	light.origin = tuple_new_point(0, 0, 10);
	light.intensity = color_new(1, 1, 1);
	eyev = tuple_new_vector(0, 0, -1);
	normalv = tuple_new_vector(0, 0, -1);
	result = light_tests(&s.material, &light, p, eyev, normalv);
	assert(is_approx_equal(result.x, 0.1, M_EPSILON));
	assert(is_approx_equal(result.y, 0.1, M_EPSILON));
	assert(is_approx_equal(result.z, 0.1, M_EPSILON));
}
