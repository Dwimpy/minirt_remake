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

int main(void) {
	t_window	window;
	t_image		canvas;
	t_shape		plane;

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
	camera_tests();
//	window_create(&window, 1920, 1080);
//	window_add_image(window.mlx, &canvas);
//
//
//	window_draw_loop(window.mlx);
	return (0);
}
