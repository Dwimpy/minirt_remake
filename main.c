/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:59:09 by arobu             #+#    #+#             */
/*   Updated: 2023/08/09 05:47:01 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "image.h"
#include "intersect.h"
#include "material.h"
#include "matrix.h"
#include "onb.h"
#include "quaternion.h"
#include "ray.h"
#include "shape.h"
#include "sphere.h"
#include "transform.h"
#include "tuple.h"
#include "vector.h"
#include "window.h"
#include "light.h"
#include "time.h"
#include "camera.h"
#include "plane.h"
#include "scene.h"

void run_tests()
{
	tuple_tests();
	onb_tests();
}
//
//void run_sphere_test(t_image canvas) {
//	t_vector vector;
//	t_vector_iterator it;
//
//	srand48(time(NULL));
//	vector = vector_init(5, sizeof(t_shape));
//	t_shape sphere;
//	t_shape sphere2;
//	t_shape sphere3;
//	t_shape *curr_shape;
//	t_tuple origin;
//	t_tuple origin2;
//	t_tuple origin3;
//	bool is_hit;
//	double tmax;
//	t_ray ray;
//	t_color color = color_new(0.2, 0.2, 0.8)	;
//
//	origin = tuple_new_point(960.0, 540.0, -1000.0);
//	origin2 = tuple_new_point(255.0, 255.0, -1000.0);
//	origin3 = tuple_new_point(1255.0, 745.0, -1000.0);
//	sphere = shape_new_sphere(origin, 150.0, color);
//	sphere2 = shape_new_sphere(origin2, 150.0, color);
//	sphere3 = shape_new_sphere(origin3, 150.0, color);
//	ft_memset(&rec, 0, sizeof(t_hit_record));
//	vector_pushback(&vector, &sphere);
//	vector_pushback(&vector, &sphere2);
//	vector_pushback(&vector, &sphere3);
//	vector_iterator_begin(&it, &vector);
//	for (uint32_t i = 0; i < canvas.width; i++) {
//		for (uint32_t j = 0; j < canvas.height; j++) {
//			tmax = M_INFINITY;
//			is_hit = false;
//			ray = (t_ray) {tuple_new_point(i, j, 0.0), tuple_new_vector(0, 0, -1)};
//			it.index = 0;
//			while (!it.end(&it)) {
//				curr_shape = (t_shape *) it.get(&it);
//				rec.shape = curr_shape;
//				if (curr_shape->vtable.hit(ray, .00001, tmax, &rec)) {
//					tmax = rec.t;
//					is_hit = true;
//				}
//				if (is_hit)
//					image_set_pixel(canvas, rec.color, i, j);
//				else
//					image_set_pixel(canvas, color_new(0.2, 0.2, 0.2), i, j);
//				it.next(&it);
//			}
//		}
//	}
//}

typedef struct s_projectile {
	t_tuple position;
	t_tuple velocity;
} t_projectile;

typedef struct s_environment {
	t_tuple gravity;
	t_tuple wind;
} t_environment;

t_projectile tick(t_projectile p, t_environment e)
{
	p.position = tuple_add(p.position, p.velocity);
	p.velocity = tuple_add(p.velocity, (tuple_add(e.wind, e.gravity)));
	return (p);
}

void projectile_test(t_image canvas)
{
	t_projectile p = (t_projectile) {tuple_new_point(0.0, 1.0, 0.0), tuple_normalize(tuple_new_vector(0.8, 1, 0.0))};
	t_environment e = (t_environment) {tuple_new_vector(0, -0.1, 0), tuple_new_vector(-0.01, 0, 0)};
	p.velocity = tuple_multiply_s(p.velocity, 17.0);

	while (p.position.y >= 0)
	{
		if (p.position.x > canvas.width || (canvas.height - p.position.y) <= 0)
			break;
		image_set_pixel(canvas, color_new(1.0, 0.0, 0.0), p.position.x, canvas.height - p.position.y);
		p = tick(p, e);
	}
}

void sphere_test(t_image canvas)
{
	t_shape sphere;
	t_shape sphere1;
	t_real wall_z;
	t_real wall_size;
	t_real half;
	t_real pixel_size;
	t_real world_y;
	t_real world_x;
	t_tuple pos;
	size_t i;
	size_t j;
	t_ray ray;
	t_tuple ray_origin;
	t_vector world;
	clock_t t;
	t_light light;
	t_computations comps;

	wall_size = 10;
	wall_z = 10;
	half = wall_z / 2;
	pixel_size = wall_size / canvas.height;
	world = vector_init(2, sizeof(t_shape));
	comps.intersections = vector_init(2, sizeof(t_intersect));
	ray_origin = tuple_new_point(0, 0, -5.0);
	sphere = shape_new_sphere(1.0);
	sphere1 = shape_new_sphere(1.0);
	j = 0;
	sphere.material = material_default(color_new(1, 0.2, 1));
	sphere1.material = material_default(color_new(0.5, 0.2, 1));
	light.origin = tuple_new_point(-10.0, 10, -10.0);
	light.intensity = color_new(1, 1, 1);
	vector_pushback(&world, &sphere);
	t = clock();
	while (j < canvas.height - 1)
	{
		world_y = half - pixel_size * (t_real) j;
		i = 0;
		while (i < canvas.width - 1)
		{
			world_x = -half + (pixel_size) * (t_real) i;
			tuple_set(&pos, world_x, world_y, wall_z);
			ray_set(&ray, ray_origin, tuple_normalize(tuple_subtract(pos, ray.origin)));
			image_set_pixel(canvas, intersect_color_at(&world, ray, &comps, &light, MAX_DEPTH), i, j);
			vector_clear(&comps.intersections);
			i++;
		}
		j++;
	}

	t = clock() - t;
	double time_taken = ((double) t) / CLOCKS_PER_SEC; // in seconds
	printf("fun() took %f seconds to execute \n", time_taken);
}

void inside_sphere_test()
{

	t_shape sph1;
	t_shape sph2;
	t_vector world;
	t_light light;
	t_ray ray;
	t_computations comps;
	sph1 = shape_new_sphere(1.0);
	sph2 = shape_new_sphere(1.0);
//	run_tests();
	sph1.material = material_default(color_new(1, 0.2, 1));
	sph2.material = material_default(color_new(0.5, 0.2, 1));
	light.origin = tuple_new_point(-10.0, 10, -10.0);
	light.intensity = color_new(1, 1, 1);
	world = vector_init(10, sizeof(t_shape));
	comps.intersections = vector_init(10, sizeof(t_intersect));
	vector_pushback(&world, &sph1);
	vector_pushback(&world, &sph2);
	ray.origin = tuple_new_point(0, 0, 0.75);
	ray.direction = tuple_new_vector(0, 0, -1);
	tuple_print(intersect_color_at(&world, ray, &comps, &light, MAX_DEPTH));
}

void rt_tester(t_image canvas)
{
	t_shape sph1;
	t_shape sph2;
	t_shape floor;
	t_shape plane;
	t_vector world;
	t_light light;
	t_ray ray;
	t_computations comps;
	size_t i;
	size_t j;
	t_quaternion q;
	t_camera camera;

	sph1 = shape_new_sphere(5.0);
	sph2 = shape_new_sphere(5.0);
	floor = shape_new_plane();
	// run_tests();
	sph1.material = material_glass(color_new(0.0, 0.0, 0.0));
	floor.material = material_default(color_new(0.2, 0.2, 0.3));
	sph2.material = material_default(color_new(1, 0, 0.5));
	shape_set_transform(&sph2, tf_translate(0, 5, 5));
	sph1.material.ambient = 1.0;
	sph1.material.diffuse = 0.1;
	sph1.material.specular = 0.2;
	sph2.material.specular = 0.0;
	sph2.material.shininess = 200;
	floor.material.specular = 0.1;
	floor.material.transparency = 0.0;
	floor.material.reflectivity = 0.05;
	floor.material.refractive_index = 1.5;
	floor.material.ambient = 0.2;
	floor.material.diffuse = 0.05;
	light.origin = tuple_new_point(0.0, 1, -40.0);
	light.intensity = color_new(1, 1, 1);
	world = vector_init(25, sizeof(t_shape));
	comps.intersections = vector_init(25, sizeof(t_intersect));
	comps.shadow_intersections = vector_init(25, sizeof(t_intersect));
	comps.ref_index_tracker = vector_init(4, sizeof(t_shape));
	camera = camera_new(canvas.width, canvas.height, M_PI_2);
	camera.tf = camera_view_transform(tuple_new_point(0, 7, -10), tuple_new_point(0.0, 5, 0));
	shape_set_transform(&sph1, tf_translate(0, 5, 0));
	shape_set_transform(&sph2, tf_translate(10, 5, 10));
	clock_t t;
	t = clock();
	vector_pushback(&world, &sph1);
	vector_pushback(&world, &sph2);
	vector_pushback(&world, &floor);
	j = -1;
	while (++j < canvas.height - 1)
	{
		i = -1;
		while (++i < canvas.width - 1)
		{
			ray = camera_get_ray(&camera, i, j);
			image_set_pixel(canvas, intersect_color_at(&world, ray, &comps, &light,MAX_DEPTH), i, j);
			vector_clear(&comps.intersections);
			vector_clear(&comps.shadow_intersections);
			vector_clear(&comps.ref_index_tracker);
		}
	}
	t = clock() - t;
	double time_taken = ((double) t) / CLOCKS_PER_SEC; // in seconds
	printf("fun() took %f seconds to execute \n", time_taken);

	tf_free(camera.tf);
	free(sph1.data);
	free(floor.data);
	tf_free(sph1.transform);
	tf_free(floor.transform);
	vector_free(&comps.shadow_intersections);
	vector_free(&comps.intersections);
	vector_free(&world);
}

t_scene default_world()
{
	t_scene	scene;
	t_shape	s1;
	t_shape	s2;

	s1 = shape_new_sphere(1.0);
	s1.material.color = color_new(0.8, 1.0, 0.6);
	s1.material.diffuse = 0.7;
	s1.material.specular = 0.2;
	s2 = shape_new_sphere(1.0);
	s2.material = material_default(color_new(1.0, 0.5, 0.5));
	shape_set_transform(&s2, tf_scale(0.5, 0.5, 0.5));
	scene.objs = vector_init(25, sizeof(t_shape));
	scene.light.origin = tuple_new_point(-10, 10, -10);
	scene.light.intensity = color_new(1, 1, 1);
	vector_pushback(&scene.objs, &s1);
	vector_pushback(&scene.objs, &s2);
	return (scene);
}


void reflect_test()
{
	t_scene		world;
	t_ray		ray;
	t_shape 	*shape;
	t_intersect i;
	t_computations comps;
	t_shape			plane;

	world = default_world();
	plane = shape_new_plane();
	ray = ray_new(tuple_new_point(0, 0, -3), tuple_new_vector(0, -sqrt(2) / 2, sqrt(2) / 2));
	shape = vector_at(&world.objs, 1);
	plane.material = material_default(color_new(0.0, 0.0, 0.0));
	shape->material.ambient = 1;
	plane.material.reflectivity = 0.5;
	i = intersection(sqrt(2), &plane);
	i.obj = &plane;
	shape_set_transform(&plane, tf_translate(0, -2, 0));
	vector_pushback(&world.objs, &plane);
	comps.intersections = vector_init(25, sizeof(t_intersect));
	comps.shadow_intersections = vector_init(25, sizeof(t_intersect));
	comps.ref_index_tracker = vector_init(25, sizeof(t_shape));
	vector_pushback(&comps.intersections, &i);
	intersect_compute(&i, &ray, &comps);
	tuple_print(comps.reflected_dir);
	tuple_print(intersect_reflected_color(&world.objs, &comps, &world.light, 2));
}


int main(void) {
	t_window	window;
	t_image		canvas;
	t_shape		plane;

	window_create(&window, 1920, 1080);
	window_add_image(window.mlx, &canvas);


//	sphere_test(canvas);
	// inside_sphere_test();
	rt_tester(canvas);
	// reflect_test();
	window_draw_loop(window.mlx);
//	system("leaks minirt");
	return (0);
}
