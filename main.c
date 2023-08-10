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
#include "time.h"
#include <time.h>

void	run_tests(void)
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

void	run_reflection_tests(void)
{
	scene_test_reflection_vector();
	scene_test_reflected_color();
	scene_test_reflected_shade_hit();
	scene_test_refraction();
	scene_test_under_point();
	scene_test_opaque_surface();
}

int	main(void)
{
	t_window	window;
	t_image		canvas;
	t_camera	camera;
	t_scene		world;
	t_shape		plane;
	clock_t		start;

//	run_tests();
	run_reflection_tests();
//	world = scene_default();
//	plane = shape_new_plane();
//	plane.material = material_default(color_new(0.3, 0.6, 0.8));
//	plane.material.reflectivity = 0.1;
//	plane.material.diffuse = 0.05;
//	plane.material.specular = 0.07;
//	plane.material.shininess = 300;
//	plane.material.ambient = 0.05;
//	shape_set_transform(&plane, tf_translate(0, -1, 0));
//	vector_pushback(&world.objs, &plane);
//	camera = camera_new(1920, 1080, 60);
//	camera_set_view_transform(&camera, camera_view_transform(\
//				tuple_new_point(0, 0, -15), \
//					tuple_new_point(0, 0, 0), \
//						tuple_new_vector(0, 1, 0)));
//	window_create(&window, 1920, 1080);
//	window_add_image(window.mlx, &canvas);
//	start = clock();
//	scene_render(&world, &camera, &canvas);
//	printf("Rendering took: [ %f ] seconds", (double)(clock() - start) / CLOCKS_PER_SEC);
//	window_draw_loop(window.mlx);
	return (0);
}
