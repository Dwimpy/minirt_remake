/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:21:19 by arobu             #+#    #+#             */
/*   Updated: 2023/08/21 15:23:12 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   scenes.c                                           :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2023/08/09 19:11:36 by arobu             #+#    #+#             */
///*   Updated: 2023/08/09 19:11:36 by arobu            ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */
//
#include "color.h"
#include "cube.h"
#include "intersect.h"
#include "../light/light.h"
#include "material.h"
#include "plane.h"
#include "ray.h"
#include "scene.h"
#include "shape.h"
#include "sphere.h"
#include "transform.h"
#include "tuple.h"
#include "vector.h"
#include <math.h>
#include <stdio.h>

t_scene scene_default(void)
{
	t_scene world;
	t_shape s1;
	t_shape s2;
	t_shape plane;

	world.light = light_point_new(tuple_new_point(-10, 10, -10), color_new(1.0, 1.0, 1.0));
	world.objs = vector_init(10, sizeof(t_shape));
	world.intersections = vector_init(10, sizeof(t_intersect));
	world.shadow_intersections = vector_init(10, sizeof(t_intersect));
	world.comps.ref_index_tracker = vector_init(10, sizeof(t_shape **));
	s1 = shape_new_sphere();
	s2 = shape_new_sphere();
	s1.material = material_default(color_new(0.8, 1.0, 0.6));
	s1.material.diffuse = 0.7;
	s1.material.specular = 0.2;
//	s1.material.shininess = 300;
//	s1.material.transparency = 1.0;
//	s1.material.reflectivity = 1.0;
//	s1.material.ambient = 0.0;
//	s1.material.refractive_index = 1.5;
	s2.material = material_default(color_new(1.0, 1.0, 1.0));
	shape_scale(&s2, 0.5, 0.5, 0.5);
	tf_compute(&s2.transform);
	tf_compute(&s1.transform);
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

	sphere = shape_new_sphere();
	ray = ray_new(tuple_new_point(0, 0, -5), tuple_new_vector(0, 0, 1));
	i = intersection(4, &sphere);
	intersect_compute(&i, &ray, &comps, NULL);
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

	sphere = shape_new_sphere();
	ray = ray_new(tuple_new_point(0, 0, -5), tuple_new_vector(0, 0, 1));
	i = intersection(4, &sphere);
	intersect_compute(&i, &ray, &comps, NULL);
	assert(comps.inside == false);
	sphere = shape_new_sphere();
	ray = ray_new(tuple_new_point(0, 0, 0), tuple_new_vector(0, 0, 1));
	i = intersection(1, &sphere);
	intersect_compute(&i, &ray, &comps, NULL);
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
	intersect_compute(&i, &ray, &world.comps, NULL);
	color = intersect_shade_hit(&world, &world.comps, 1);
	assert(is_approx_equal(color.x, 0.38066, M_EPSILON));
	assert(is_approx_equal(color.y, 0.47582, M_EPSILON));
	assert(is_approx_equal(color.z, 0.2855, M_EPSILON));

	world.light = light_point_new(tuple_new_point(0, 0.25, 0), color_new(1, 1, 1));
	ray = ray_new(tuple_new_point(0, 0, 0), tuple_new_vector(0, 0, 1));
	shape = vector_at(&world.objs, 1);
	i = intersection(0.5, shape);
	intersect_compute(&i, &ray, &world.comps, NULL);
	color = intersect_shade_hit(&world, &world.comps, 1);
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
	color = intersect_color_at(&world, &ray, 1);
	assert(tuple_equal(color, shape->material.color));

	world = scene_default();
	ray = ray_new(tuple_new_point(0, 0, -5), tuple_new_vector(0, 1, 0));
	vector_clear(&world.intersections);
	color = intersect_color_at(&world, &ray, 1);
	assert(tuple_equal(color, tuple_new_vector(0, 0, 0)));

	ray = ray_new(tuple_new_point(0, 0, -5), tuple_new_vector(0, 0, 1));
	vector_clear(&world.intersections);
	color = intersect_color_at(&world, &ray, 1);

	assert(tuple_equal(color, tuple_new_vector(0.38066, 0.47583, 0.2855)));
}
//
//void	scene_test_shadows(void)
//{
//	t_scene	world;
//	t_tuple	point;
//
//	world = scene_default();
//	point = tuple_new_point(0, 10, 0);
//	assert(intersect_shadow_hit(&world, &point) == 0);
//
//	point = tuple_new_point(10, -10, 10);
//	assert(intersect_shadow_hit(&world, &point) == 1);
//
//	point = tuple_new_point(-20, 20, -20);
//	assert(intersect_shadow_hit(&world, &point) == 0);
//
//	point = tuple_new_point(-2, 2, -2);
//	assert(intersect_shadow_hit(&world, &point) == 0);
//
//	t_scene	world2;
//	t_shape	s1;
//	t_shape	s2;
//	t_shape	plane;
//	t_intersect inter;
//	world2.light = light_point_new(tuple_new_point(0, 0, -10), color_new(1.0, 1.0, 1.0));
//	world2.objs = vector_init(10, sizeof(t_shape));
//	world2.intersections = vector_init(10, sizeof(t_intersect));
//	world2.shadow_intersections = vector_init(10, sizeof(t_intersect));
//	s1 = shape_new_sphere(1.0);
//	s2 = shape_new_sphere(1.0);
//	s1.material = material_default(color_new(0.8, 1.0, 0.6));
//	s1.material.color = color_new(0.8, 1.0, 0.6);
//	s1.material.diffuse = 0.7;
//	s1.material.specular = 0.2;
//	s2.material = material_default(color_new(1.0, 1.0, 1.0));
//	shape_set_transform(&s2, tf_translate(0, 0, 10));
//	vector_pushback(&world2.objs, &s1);
//	vector_pushback(&world2.objs, &s2);
//	t_ray ray;
//	ray = ray_new(tuple_new_point(0, 0, 5), tuple_new_vector(0, 0, 1));
//	inter = intersection(4, &s2);
//	intersect_compute(&inter, &ray, &world2.comps, NULL);
//	vector_pushback(&world2.intersections, &inter);
//	t_color color;
//	color = intersect_shade_hit(&world2, &world2.comps, 1);
//	assert(tuple_equal(color, color_new(0.1, 0.1, 0.1)));
//
//	ray = ray_new(tuple_new_point(0, 0, -5), tuple_new_vector(0, 0, 1));
//	inter = intersection(5, &s2);
//	intersect_compute(&inter, &ray, &world2.comps, NULL);
//	assert(world2.comps.over_point.z < -M_EPSILON / 2);
//	assert(world2.comps.point.z > world2.comps.over_point.z);
//}
//
void	scene_test_reflection_vector(void)
{
	t_shape	plane;
	t_ray	ray;
	t_intersect i;
	t_computations comps;
	t_scene		world;
	t_shape 	*shape;
	t_color 	color;

	plane = shape_new_plane();
	plane.material = material_default(color_new(1, 1, 1));
	ray = ray_new(tuple_new_point(0, 1, -1), tuple_new_vector(0, -sqrt(2) / 2, sqrt(2) / 2));
	i = intersection(sqrt(2) / 2, &plane);
	intersect_compute(&i, &ray, &comps, NULL);
	assert(tuple_equal(comps.reflected_dir, tuple_new_vector(0, sqrt(2) / 2, sqrt(2) /2 )));

	world = scene_default();
	ray = ray_new(tuple_new_point(0, 0, 0), tuple_new_vector(0, 0, 1));
	shape = vector_at(&world.objs, 1);
	shape->material.ambient = 1;
	i = intersection(1, shape);
	intersect_compute(&i, &ray, &world.comps, NULL);
	color = intersect_reflected_color(&world, &comps, 1);
	assert(tuple_equal(color, color_new(0, 0, 0)));
}

void	scene_test_reflected_color(void)
{
	t_shape	plane;
	t_ray	ray;
	t_intersect i;
	t_computations comps;
	t_scene		world;
	t_shape 	*shape;
	t_color 	color;

	world = scene_default();
	plane = shape_new_plane();
	color = color_new(0, 0, 0);
	shape_translate(&plane, 0, -1, 0);
	tf_compute(&plane.transform);
	plane.material = material_default(color_new(1, 1, 1));
	plane.material.reflectivity = 0.5;
	ray = ray_new(tuple_new_point(0, 0, -3), tuple_new_vector(0, -sqrt(2) / 2, sqrt(2) / 2));
	i = intersection(sqrt(2), &plane);
	vector_pushback(&world.objs, &plane);
	vector_pushback(&world.intersections, &i);
	intersect_compute(&i, &ray, &world.comps, NULL);
	color = intersect_reflected_color(&world, &world.comps, 1);
	tuple_print(color);
	assert(tuple_equal_p(color, color_new(0.19032, 0.2379, 0.14274), M_EPSILON * 10));
}

void	scene_test_reflected_shade_hit(void)
{
	t_shape	plane;
	t_ray	ray;
	t_intersect i;
	t_computations comps;
	t_scene		world;
	t_shape 	*shape;
	t_color 	color;

	world = scene_default();
	plane = shape_new_plane();
	color = color_new(0, 0, 0);
	ray = ray_new(tuple_new_point(0, 0, -3), tuple_new_vector(0, -sqrt(2) / 2, sqrt(2) / 2));
	shape_translate(&plane, 0, -1, 0);
	plane.material = material_default(color_new(1, 1, 1));
	plane.material.reflectivity = 0.5;
	i = intersection(sqrt(2), &plane);
	vector_pushback(&world.intersections, &i);
	vector_pushback(&world.objs, &plane);
	intersect_compute(&i, &ray, &world.comps, NULL);
	color = intersect_shade_hit(&world, &world.comps, 1);
	tuple_print(color);
	assert(tuple_equal_p(color, color_new(0.876, 0.924, 0.829), M_EPSILON * 10));
}
//
//void	scene_test_refraction(void)
//{
//	t_shape	gs;
//	t_shape	gs1;
//	t_shape	gs2;
//	t_ray	ray;
//	t_vector	isect;
//	t_intersect	i1;
//	t_intersect	i2;
//	t_intersect	i3;
//	t_intersect	i4;
//	t_intersect	i5;
//	t_intersect	i6;
//	t_computations comps;
//
//	gs = shape_new_sphere(1.0);
//	gs1 = shape_new_sphere(1.0);
//	gs2 = shape_new_sphere(1.0);
//	gs.material = material_glass();
//	gs1.material = material_glass();
//	gs1.material.refractive_index = 2.0;
//	gs2.material = material_glass();
//	gs2.material.refractive_index = 2.5;
//	isect = vector_init(10, sizeof(t_intersect));
//	shape_set_transform(&gs, tf_scale(2, 2, 2));
//	shape_set_transform(&gs1, tf_translate(0, 0, -0.25));
//	shape_set_transform(&gs2, tf_translate(0, 0, 0.25));
//	i1 = intersection(2, &gs);
//	i2 = intersection(2.75, &gs1);
//	i3 = intersection(3.25, &gs2);
//	i4 = intersection(4.75, &gs1);
//	i5 = intersection(5.25, &gs2);
//	i6 = intersection(6, &gs);
//	vector_pushback(&isect, &i1);
//	vector_pushback(&isect, &i2);
//	vector_pushback(&isect, &i3);
//	vector_pushback(&isect, &i4);
//	vector_pushback(&isect, &i5);
//	vector_pushback(&isect, &i6);
//	comps.ref_index_tracker = vector_init(10, sizeof(t_shape **));
//	ray = ray_new(tuple_new_point(0, 0, -4), tuple_new_vector(0, 0, 1));
//	intersect_compute(&i1, &ray, &comps, &isect);
////	printf("idx: 0\tn1: %f\tn2: %f\n", comps.n1, comps.n2);
//	intersect_compute(&i2, &ray, &comps, &isect);
////	printf("idx: 1\tn1: %f\tn2: %f\n", comps.n1, comps.n2);
//	intersect_compute(&i3, &ray, &comps, &isect);
////	printf("idx: 2\tn1: %f\tn2: %f\n", comps.n1, comps.n2);
//	intersect_compute(&i4, &ray, &comps, &isect);
////	printf("idx: 3\tn1: %f\tn2: %f\n", comps.n1, comps.n2);
//	intersect_compute(&i5, &ray, &comps, &isect);
////	printf("idx: 4\tn1: %f\tn2: %f\n", comps.n1, comps.n2);
//	intersect_compute(&i6, &ray, &comps, &isect);
////	printf("idx: 5\tn1: %f\tn2: %f\n", comps.n1, comps.n2);
//
//}

void	scene_test_under_point(void)
{
	t_ray	ray;
	t_shape	sphere;
	t_intersect isect;
	t_computations comps;

	ray = ray_new(tuple_new_point(0, 0, -5), tuple_new_vector(0, 0, 1));
	sphere = shape_new_sphere();
	sphere.material = material_glass();
	shape_translate(&sphere, 0, 0, 1);
	tf_compute(&sphere.transform);
	isect = intersection(5, &sphere);
	intersect_compute(&isect, &ray, &comps, NULL);
	assert(comps.under_point.z > M_EPSILON / 2);
	assert(comps.point.z < comps.under_point.z);

}

void	scene_test_opaque_surface(void)
{
	t_scene	world;
	t_shape	*shape;
	t_ray	ray;
	t_intersect i1;
	t_intersect i2;
	t_color 	color;

	world = scene_default();
	shape = vector_at(&world.objs, 0);
	shape->material.transparency = 1.0;
	shape->material.refractive_index = 1.5;
	ray = ray_new(tuple_new_point(0, 0, sqrt(2) / 2), tuple_new_vector(0, 1, 0));
	i1 = intersection(-sqrt(2) / 2, shape);
	i2 = intersection(sqrt(2) / 2, shape);
	vector_pushback(&world.intersections, &i1);
	vector_pushback(&world.intersections, &i2);
	intersect_compute(&i2, &ray, &world.comps, &world.intersections);
	color = intersect_refracted_color(&world, &world.comps, 5);
	tuple_print(color);
}

void scene_test_refracted_color(void)
{
	t_scene world;
	t_ray ray;
	t_intersect i1;
	t_color color;
	t_shape floor;
	t_shape ball;

	world = scene_default();
	floor = shape_new_plane();
	ball = shape_new_sphere();
	color = color_new(0, 0, 0);
	floor.material = material_default(color_new(1.0, 1.0, 1.0));
	floor.material.transparency = 0.5;
	floor.material.refractive_index = 1.5;
	shape_translate(&floor, 0, -1, 0);
	tf_compute(&floor.transform);
	ball.material = material_default(color_new(1.0, 0.0, 0.0));
	ball.material.ambient = 0.5;
	shape_translate(&floor, 0, -3.5, -0.5);
	tf_compute(&floor.transform);
	vector_pushback(&world.objs, &floor);
	vector_pushback(&world.objs, &ball);
	ray = ray_new(tuple_new_point(0.0, 0.0, -3.0), tuple_new_vector(0.0, -sqrt(2.0) / 2.0, sqrt(2.0) / 2.0));
	i1 = intersection(sqrt(2.0), &floor);
	vector_pushback(&world.intersections, &i1);
	intersect_compute(&i1, &ray, &world.comps, &world.intersections);
	color = intersect_shade_hit(&world, &world.comps, 5);
	tuple_print(color);
}

t_scene	cornell_box(void)
{
	t_scene	world;
	t_shape	floor;
	t_shape	ceiling;
	t_shape	right;
	t_shape	left;
	t_shape	back;
	t_shape	box1;
	t_shape	box2;
	t_shape sphere;
	t_real	dimension;

	dimension = 550.0 / 2.0;
//	world.light = light_point_new(tuple_new_point(100, 100, -800 + dimension), color_new(0.43, 0.43, 0.43));
	world.light = light_rect_new(tuple_new_point(100, dimension + 50, -800 + dimension), color_new(0.43, 0.43, 0.43),
								 tuple_new_vector(1, 0, 1), coord_new(70, 70), 5);
	world.objs = vector_init(10, sizeof(t_shape));
	world.intersections = vector_init(10, sizeof(t_intersect));
	world.shadow_intersections = vector_init(10, sizeof(t_intersect));
	world.comps.ref_index_tracker = vector_init(10, sizeof(t_shape **));
	floor = shape_new_cube();
	ceiling = shape_new_cube();
	right = shape_new_cube();
	left = shape_new_cube();
	back = shape_new_cube();
	sphere = shape_new_sphere();
	shape_scale(&sphere, 50, 50, 50);
	shape_translate(&sphere, dimension / 2.0, 50, dimension + dimension / 2);
	box1 = shape_new_cube();
	box2 = shape_new_cube();
	sphere = shape_new_sphere();

	shape_scale(&sphere, 50, 50, 50);
	shape_translate(&sphere, 310, 50, dimension + 75);
	tf_compute(&sphere.transform);

	shape_scale(&floor, dimension, 1, dimension);
	shape_translate(&floor, dimension, 0, 2 * dimension);
	tf_compute(&floor.transform);

	shape_scale(&ceiling, dimension, 1, dimension);
	shape_translate(&ceiling, dimension, 2 * dimension, 2 * dimension);
	tf_compute(&ceiling.transform);

	shape_scale(&left, 1, dimension, dimension);
	shape_translate(&left, 0, dimension, 2 * dimension);
	tf_compute(&left.transform);

	shape_scale(&right, 1, dimension, dimension);
	shape_translate(&right, 2 * dimension, dimension, 2 * dimension);
	tf_compute(&right.transform);

	shape_scale(&back, dimension, dimension, 1);
	shape_translate(&back, dimension, dimension, 3 * dimension);
	tf_compute(&back.transform);

	shape_scale(&box1, 50, 50, 50);
	shape_rotate(&box1, 0, -25, 0);
	shape_translate(&box1, 110, 50, dimension + 250);
	tf_compute(&box1.transform);

	shape_scale(&box2, 50, 25, 50);
	shape_rotate(&box2, 0, 25, 0);
	shape_translate(&box2, 444, 25, dimension + 200);
	tf_compute(&box2.transform);

	floor.material = material_lambertian(color_new(0.73, 0.73, 0.73));
	ceiling.material = material_lambertian(color_new(0.73, 0.73, 0.73));
	right.material = material_lambertian(color_new(0.12, 0.45, 0.15));
	left.material = material_lambertian(color_new(0.63, 0.05, 0.05));
	back.material = material_lambertian(color_new(0.73, 0.73, 0.73));
	sphere.material = material_glass();

	box1.material = material_copper();
	box2.material = material_copper();

	vector_pushback(&world.objs, &floor);
	vector_pushback(&world.objs, &ceiling);
	vector_pushback(&world.objs, &right);
	vector_pushback(&world.objs, &left);
	vector_pushback(&world.objs, &back);
	vector_pushback(&world.objs, &sphere);
	vector_pushback(&world.objs, &box1);
	vector_pushback(&world.objs, &box2);
	return (world);
}

void	intersect_is_shadowed(void)
{
	t_scene	world;
	t_tuple	light_pos;
	t_tuple	point;
	bool	is_shadow;

	world = scene_default();
	light_pos = tuple_new_point(-10, -10, -10);
	point = tuple_new_point(-10, -10, 10);
	is_shadow = intersect_shadow_hit(&world, &light_pos, &point);
	assert(is_shadow == false);
	point = tuple_new_point(10, 10, 10);
	is_shadow = intersect_shadow_hit(&world, &light_pos, &point);
	assert(is_shadow == true);
	point = tuple_new_point(-20, -20, -20);
	is_shadow = intersect_shadow_hit(&world, &light_pos, &point);
	assert(is_shadow == false);
	point = tuple_new_point(-5, -5, -5);
	is_shadow = intersect_shadow_hit(&world, &light_pos, &point);
	assert(is_shadow == false);
}

void	test_light_intensity_at(void)
{
	t_scene	world;
	t_light	light;
	t_real	intensity;
	t_tuple	point;

	world = scene_default();
	light = world.light;
	point = tuple_new_point(0, 1.0001, 0);
	intensity = light_intensity_at(&world, &light, &point);
	assert(intensity == 1.0);
	point = tuple_new_point(-1.0001, 0, 0);
	intensity = light_intensity_at(&world, &light, &point);
	assert(intensity == 1.0);
	point = tuple_new_point(0, 0, -1.0001);
	intensity = light_intensity_at(&world, &light, &point);
	assert(intensity == 1.0);
	point = tuple_new_point(0, 0, 1.0001);
	intensity = light_intensity_at(&world, &light, &point);
	assert(intensity == 0.0);
	point = tuple_new_point(1.0001, 0, 0);
	intensity = light_intensity_at(&world, &light, &point);
	assert(intensity == 0.0);
	point = tuple_new_point(0, -1.0001, 0);
	intensity = light_intensity_at(&world, &light, &point);
	assert(intensity == 0.0);
	point = tuple_new_point(0, 0, 0);
	intensity = light_intensity_at(&world, &light, &point);
	assert(intensity == 0.0);
}

void	test_frac_intensity(void)
{
	t_scene	world;
	t_shape *shape;
	t_color	intensity;
	t_tuple	point;
	t_tuple	eye;
	t_tuple	normal;

	world = scene_default();
	world.light = light_rect_new(tuple_new_point(0, 0, 0), color_new(1, 1, 1), tuple_new_vector(0, 0, 1), coord_new(10, 10), 10);
	printf("POINT ON LIGHT\n");
	tuple_print(light_point_on(&world.light, 0, 0));
	point = tuple_new_point(5, 5, 5);
	printf("Intensity at: %f\n", light_intensity_at(&world, &world.light, &point));
}

