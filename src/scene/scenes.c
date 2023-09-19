/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:21:19 by arobu             #+#    #+#             */
/*   Updated: 2023/09/19 12:08:36 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "cube.h"
#include "../light/light.h"
#include "scene.h"
#include "sphere.h"


t_scene	scene_default(void)
{
	t_scene world;
	t_shape s1;
	t_shape s2;
	t_shape plane;

	world.light = light_point_new(tuple_new_point(-10, 10, -10), color_new(1.0, 1.0, 1.0));
	world.objs = vector_init(10, sizeof(t_shape));
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
	world.light = light_rect_new((t_rect_light_params)
		{
			tuple_new_point(0, 5, -100),  // from
			color_multiply_s(color_new(0.94, 0.94, 0.94), 1),  //rgb + ratio
			tuple_new_vector(0, 0, 1),  // to 
			coord_new(32, 32), 2 // size of rectangle "quality of light"
		}); // i need only this for the light create a new function
	world.objs = vector_init(10, sizeof(t_shape));
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
	// sphere.material = material_glass();

	box1.material = material_copper();
	box2.material = material_copper();

	// vector_pushback(&world.objs, &floor);
	// vector_pushback(&world.objs, &ceiling);
	// vector_pushback(&world.objs, &right);
	// vector_pushback(&world.objs, &left);
	// vector_pushback(&world.objs, &back);
	// vector_pushback(&world.objs, &sphere);
	// vector_pushback(&world.objs, &box1);
	// vector_pushback(&world.objs, &box2);
	return (world);
}
