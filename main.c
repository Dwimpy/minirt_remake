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
#include "cube.h"
#include "cylinder.h"
#include "disk.h"
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
#include "time.h"
#include <time.h>

void run_tests(void)
{
//	tuple_tests();
//	matrix_tests();
//	transform_tests();
//	ray_tests();
//	sphere_tests();
//	scene_test_isect_world();
//	scene_test_isect_computations();
//	scene_test_normal_face();
//	scene_test_shade_hit();
//	scene_test_color_at();
//	camera_tests();
//	scene_test_shadows();

}

void run_reflection_tests(void)
{
//	scene_test_reflection_vector();
//	scene_test_reflected_color();
//	scene_test_reflected_shade_hit();
//	scene_test_refraction();
//	scene_test_under_point();
//	scene_test_opaque_surface();
//	scene_test_refracted_color();
}

int main(void)
{
	t_window window;
	t_image canvas;
	t_camera camera;
	t_scene world;
	t_shape plane;
	clock_t start;
	t_shape disk;
	t_shape cylinder;
//
	run_tests();
//	run_reflection_tests();
//	cube_tests();
//	world = scene_default();
//	plane = shape_new_plane();
//	plane.material = material_default(color_new(0.3, 0.6, 0.8));
//	plane.material.reflectivity = 0.1;
//	plane.material.diffuse = 0.05;
//	plane.material.specular = 0.07;
//	plane.material.shininess = 300;
//	plane.material.ambient = 0.1;
//	t_shape cube;
//	cube = shape_new_cube();
//	cube.material = material_default(color_new(0.3, 0.5, 0.5));
//	cube.material.specular = 0.6;
//	cube.material.ambient = 0.1;
//	cube.material.shininess = 200;
//	cube.material.diffuse = 0.4;
//	cylinder = shape_new_cylinder(1.0, 2.0, true);
//	cylinder.material = material_default(color_new(.5, 0.3, 0.2));
//	cylinder.material.diffuse = 0.3;
//	cylinder.material.specular = 0.5;
//	disk = shape_new_disk();
//	disk.material = material_default(color_new(.5, 0.3, 0.2));
//	disk.material.diffuse = 0.3;
//	disk.material.specular = 0.5;
//	shape_set_transform(&plane, tf_translate(0, -2, 0));
//	shape_set_transform(&cube, tf_transform(tf_rotate(25, 0, 0), tf_scale(1, 1, 1), tf_translate(3, 0, 2)));
//	shape_set_transform(&cylinder, tf_transform(tf_rotate(-25, 0, 0), tf_scale(2, 2, 2), tf_translate(2, 2, 5)));
//	shape_set_transform(&disk, tf_transform(tf_rotate(-25, 0, 0), tf_scale(1, 1, 1), tf_translate(-4, 2, 5)));
//	vector_pushback(&world.objs, &plane);
//	vector_pushback(&world.objs, &cube);
//	vector_pushback(&world.objs, &cylinder);
//	vector_pushback(&world.objs, &disk);

	world = cornell_box();
	camera = camera_new(2300, 2300 / 1.7777778, 50);
	camera_set_view_transform(&camera, camera_view_transform(\
				tuple_new_point(278.0, 278.0, -800), \
					tuple_new_point(278.0, 278.0, 0.0), \
                    tuple_new_vector(0, -1, 0)));
//		camera_set_view_transform(&camera, camera_view_transform(\
//				tuple_new_point(0.0, 0.0, -25), \
//					tuple_new_point(0.0, 0.0, 0.0), \
//                    tuple_new_vector(0, 1, 0)));
	camera.tf.inv_tf = matrix_inverse(camera.tf.tf);
	window_create(&window, camera.width, camera.height);
	window_add_image(window.mlx, &canvas);
	start = clock();
	scene_render(&world, &camera, &canvas);
	printf("Rendering took: [ %f ] seconds", (double)(clock() - start) / CLOCKS_PER_SEC);
	window_draw_loop(window.mlx);
	return (0);
}
