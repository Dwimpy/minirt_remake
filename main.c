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
#include "pdf_cuboid.h"
#include "quaternion.h"
#include "ray.h"
#include "shape.h"
#include "sphere.h"
#include "transform.h"
#include "tuple.h"
#include "vector.h"
#include "window.h"
#include "src/light/light.h"
#include "time.h"
#include "camera.h"
#include "plane.h"
#include "scene.h"
#include "time.h"
#include <math.h>
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

void	run_is_shadow_tests(void)
{
	intersect_is_shadowed();
	test_light_intensity_at();
	test_frac_intensity();
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

	run_is_shadow_tests();
//    unsigned int seed = (unsigned int)time(0) ^ (unsigned int)getpid();
//    srand48(seed);
	world = cornell_box();
	camera = camera_new(1920, 1080, 50);
	camera_view_transform(&camera, \
				tuple_new_point(278.0, 278.0, -800), \
					tuple_new_point(278.0, 278.0, 0.0));
	window_create(&window, (int32_t) camera.width, (int32_t) camera.height);
	printf("CAMERA: \n");
	tuple_print(camera.onb.up);
	tuple_print(camera.onb.left);
	tuple_print(camera.onb.forward);
//	window_add_image(window.mlx, &canvas);
//	start = clock();
//	scene_render(&world, &camera, &canvas);
//	printf("Rendering took: [ %f ] seconds", (double)(clock() - start) / CLOCKS_PER_SEC);
//	window_draw_loop(window.mlx);
	return (0);
}
