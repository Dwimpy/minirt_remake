/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:11:36 by arobu             #+#    #+#             */
/*   Updated: 2023/08/09 19:11:36 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "intersect.h"
#include "light.h"
#include "material.h"
#include "ray.h"
#include "scene.h"
#include "shape.h"
#include "sphere.h"
#include "transform.h"
#include "tuple.h"
#include "vector.h"
#include <stdio.h>

t_scene scene_default(void)
{
	t_scene world;
	t_shape s1;
	t_shape s2;

	world.light = light_new(tuple_new_point(-10, 10, -10), color_new(1.0, 1.0, 1.0));
	world.objs = vector_init(10, sizeof(t_shape));
	world.intersections = vector_init(10, sizeof(t_intersect));
	s1 = shape_new_sphere(1.0);
	s2 = shape_new_sphere(1.0);
	s1.material = material_default(color_new(0.8, 1.0, 0.6));
	s1.material.color = color_new(0.8, 1.0, 0.6);
	s1.material.diffuse = 0.7;
	s1.material.specular = 0.2;
	s2.material = material_default(color_new(1.0, 1.0, 1.0));
	shape_set_transform(&s2, tf_scale(0.5, 0.5, 0.5));
	vector_pushback(&world.objs, &s1);
	vector_pushback(&world.objs, &s2);
	return (world);
}

void scene_test_isect_world(void)
{
	t_scene world;
	t_ray ray;
	t_vector_iterator it;
	t_intersect *i;
	size_t count;

	count = 0;
	world = scene_default();
	ray = ray_new(tuple_new_point(0, 0, -5), tuple_new_vector(0, 0, 1));
	intersect_world(&world, &ray);
	vector_iterator_begin(&it, &world.intersections);
//	printf("Count: %zu\n", world.intersections.size);
	while (!it.end(&it))
	{
		i = it.get(&it);
//		printf("I[%zu]: %f\n", count, i->t);
		it.next(&it);
		count++;
	}
	assert(world.intersections.size == 4);
	i = vector_at(&world.intersections, 0);
	assert(is_approx_equal(i->t, 4.0, M_EPSILON));
	i = vector_at(&world.intersections, 1);
	assert(is_approx_equal(i->t, 4.5, M_EPSILON));
	i = vector_at(&world.intersections, 2);
	assert(is_approx_equal(i->t, 5.5, M_EPSILON));
	i = vector_at(&world.intersections, 3);
	assert(is_approx_equal(i->t, 6.0, M_EPSILON));
}

void	scene_test_isect_computations(void)
{
	t_shape 			sphere;
	t_ray				ray;
	t_intersect			i;
	t_computations		comps;

	sphere = shape_new_sphere(1.0);
	ray = ray_new(tuple_new_point(0, 0, -5), tuple_new_vector(0, 0, 1));
	i = intersection(4, &sphere);
	intersect_compute(&i, &ray, &comps);
//	printf("----------------------------");
//	printf("Shape: %d\n", comps.shape == &sphere);
//	printf("t: %f\n", comps.t);
//	tuple_print(comps.point);
//	tuple_print(comps.eye);
//	tuple_print(comps.normal);
//	printf("----------------------------");
	assert(comps.t == i.t);
	assert(comps.shape == i.obj);
	assert(tuple_equal(comps.point, tuple_new_point(0, 0, -1)));
	assert(tuple_equal(comps.eye, tuple_new_vector(0, 0, -1)));
	assert(tuple_equal(comps.normal, tuple_new_vector(0, 0, -1)));

}

void	scene_test_normal_face(void)
{
	t_shape 			sphere;
	t_ray				ray;
	t_intersect			i;
	t_computations		comps;

	sphere = shape_new_sphere(1.0);
	ray = ray_new(tuple_new_point(0, 0, -5), tuple_new_vector(0, 0, 1));
	i = intersection(4, &sphere);
	intersect_compute(&i, &ray, &comps);
	assert(comps.inside == false);
	sphere = shape_new_sphere(1.0);
	ray = ray_new(tuple_new_point(0, 0, 0), tuple_new_vector(0, 0, 1));
	i = intersection(1, &sphere);
	intersect_compute(&i, &ray, &comps);
	assert(comps.inside == true);
	assert(tuple_equal(comps.point, tuple_new_point(0, 0, 1)));
	assert(tuple_equal(comps.eye, tuple_new_vector(0, 0, -1)));
	assert(tuple_equal(comps.normal, tuple_new_vector(0, 0, -1)));
}

void	scene_test_shade_hit(void)
{
	t_scene		world;
	t_ray		ray;
	t_intersect	i;
	t_shape		*shape;
	t_color		color;

	world = scene_default();
	ray = ray_new(tuple_new_point(0, 0, -5), tuple_new_vector(0, 0, 1));
	shape = vector_at(&world.objs, 0);
	i = intersection(4, shape);
	intersect_compute(&i, &ray, &world.comps);
	color = intersect_shade_hit(&world, &world.comps);
	assert(is_approx_equal(color.x, 0.38066, M_EPSILON));
	assert(is_approx_equal(color.y, 0.47583, M_EPSILON));
	assert(is_approx_equal(color.z, 0.2855, M_EPSILON));

	world.light = light_new(tuple_new_point(0, 0.25, 0), color_new(1, 1, 1));
	ray = ray_new(tuple_new_point(0, 0, 0), tuple_new_vector(0, 0, 1));
	shape = vector_at(&world.objs, 1);
	i = intersection(0.5, shape);
	intersect_compute(&i, &ray, &world.comps);
	color = intersect_shade_hit(&world, &world.comps);
	assert(is_approx_equal(color.x, 0.90498, M_EPSILON));
	assert(is_approx_equal(color.y, 0.90498, M_EPSILON));
	assert(is_approx_equal(color.z, 0.90498, M_EPSILON));
}

void	scene_test_color_at(void)
{
	t_scene		world;
	t_ray		ray;
	t_intersect	i;
	t_shape		*shape;
	t_color		color;

	world = scene_default();
	ray = ray_new(tuple_new_point(0, 0, 0.75), tuple_new_vector(0, 0, -1));
	shape = vector_at(&world.objs, 0);
	shape->material.ambient = 1;
	shape = vector_at(&world.objs, 1);
	shape->material.ambient = 1;
	color = intersect_color_at(&world, &ray);
	assert(tuple_equal(color, shape->material.color));

	world = scene_default();
	ray = ray_new(tuple_new_point(0, 0, -5), tuple_new_vector(0, 1, 0));
	vector_clear(&world.intersections);
	color = intersect_color_at(&world, &ray);
	assert(tuple_equal(color, tuple_new_vector(0, 0, 0)));

	ray = ray_new(tuple_new_point(0, 0, -5), tuple_new_vector(0, 0, 1));
	vector_clear(&world.intersections);
	color = intersect_color_at(&world, &ray);
	assert(tuple_equal(color, tuple_new_vector(0.38066, 0.47583, 0.2855)));
}