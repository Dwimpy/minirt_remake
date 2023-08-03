/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:59:09 by arobu             #+#    #+#             */
/*   Updated: 2023/07/30 17:15:29 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "color.h"
#include "image.h"
#include "matrix.h"
#include "onb.h"
#include "ray.h"
#include "rng.h"
#include "shape.h"
#include "sphere.h"
#include "tuple.h"
#include "window.h"
#include "vector.h"
#include <stdint.h>
#include <stdlib.h>
#include "intersect.h"
#include "transform.h"

void run_tests() {
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
//	t_color color = color_new(0.2, 0.2, 0.8);
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

t_projectile tick(t_projectile p, t_environment e) {
	p.position = tuple_add(p.position, p.velocity);
	p.velocity = tuple_add(p.velocity, (tuple_add(e.wind, e.gravity)));
	return (p);
}

void projectile_test(t_image canvas) {
	t_projectile p = (t_projectile) {tuple_new_point(0.0, 1.0, 0.0), tuple_normalize(tuple_new_vector(0.8, 1, 0.0))};
	t_environment e = (t_environment) {tuple_new_vector(0, -0.1, 0), tuple_new_vector(-0.01, 0, 0)};
	p.velocity = tuple_multiply_s(p.velocity, 17.0);

	while (p.position.y >= 0) {
		if (p.position.x > canvas.width || (canvas.height - p.position.y) <= 0)
			break;
		image_set_pixel(canvas, color_new(1.0, 0.0, 0.0), p.position.x, canvas.height - p.position.y);
		p = tick(p, e);
	}
}

void sphere_test(t_image canvas) {
	t_shape sphere;
	t_real wall_z;
	t_real wall_size;
	t_real half;
	t_real pixel_size;
	t_real world_y;
	t_real world_x;
	t_real aspect_ratio;
	t_tuple pos;
	size_t i;
	size_t j;
	t_ray ray;
	t_tuple ray_origin;
	t_vector intersections;
	t_transform tf;

	wall_size = 10;
	wall_z = 10;
	half = wall_z / 2;
	aspect_ratio = (double) canvas.width / (double) canvas.height;
	pixel_size = wall_size / canvas.height;
	ray_origin = tuple_new_point(0, 0, -5.0);
	sphere = shape_new_sphere(tuple_new_point(0, 0, 0), 1, color_new(1, 0, 0));
	intersections = vector_init(100, sizeof(t_intersect));
	j = 0;
	while (j < canvas.height - 1) {
		world_y = half - pixel_size * (t_real) j;
		i = 0;
		while (i < canvas.width - 1) {
			world_x = -half + (pixel_size) * (t_real) i;
			pos = tuple_new_point(world_x, world_y, wall_z);
			ray = ray_new(ray_origin, tuple_normalize(tuple_subtract(pos, ray.origin)));
			if (sphere.vtable.intersect(&sphere, ray, &intersections) && \
			intersect_hit((t_intersect *) vector_back(&intersections)))
				image_set_pixel(canvas, sphere.vtable.get_color(&sphere), i, j);
			i++;
		}
		j++;
	}
}

int main(void) {
	t_window window;
	t_image canvas;
	t_matrix matrix;
	t_matrix matrix2;
	t_ray ray;
	t_vector vector;
	t_vector intersections;
	t_shape sphere;
	double	t;
	t_transform	scale;
	t_transform	translate;

//	scale = tf_scale(2, 2, 2);
//	translate = tf_translate(5, 0, 0);
//	t_tuple origin = tuple_new_point(0.0, 0.0, 0.0);
//	ray = ray_new(tuple_new_point(0, 0, -5), tuple_new_vector(0, 0, 1));
//	sphere = shape_new_sphere(origin, 1, color_new(1, 0, 0));
//	vector = vector_init(5, sizeof(int));
//	intersections = vector_init(10, sizeof(t_intersect));
//	shape_set_transform(&sphere, scale);
//	sphere.vtable.intersect(&sphere, ray, &intersections);
//	tuple_print(ray.origin);
//	tuple_print(ray.direction);
//	if (intersections.size != 0)
//	{
//		printf("%f\t", (*(t_intersect *)vector_at(&intersections, 0)).t[0]);
//		printf("%f\t", (*(t_intersect *)vector_at(&intersections, 0)).t[1]);
//		printf("%zu\t", (*(t_intersect *)vector_at(&intersections, 0)).count);
//		printf("Hit: %d\t", intersect_hit((*(t_intersect *)vector_at(&intersections, 0)), &t));
//		printf("t: %f\n", t);
//	}

//	run_tests();

//	projectile_test(canvas);
//	run_sphere_test(canvas);
	window_create(&window, 1920, 1080);
	window_add_image(window.mlx, &canvas);
	sphere_test(canvas);
	window_draw_loop(window.mlx);
	return (0);
}