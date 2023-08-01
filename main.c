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

#include "color.h"
#include "image.h"
#include "matrix.h"
#include "onb.h"
#include "rng.h"
#include "shape.h"
#include "sphere.h"
#include "tuple.h"
#include "window.h"
#include "vector.h"
#include <stdint.h>
#include <stdlib.h>

void run_tests() {
	tuple_tests();
	onb_tests();
}

void run_sphere_test(t_image canvas) {
	t_vector vector;
	t_vector_iterator it;

	srand48(time(NULL));
	vector = vector_init(5, sizeof(t_shape));
	t_shape sphere;
	t_shape sphere2;
	t_shape sphere3;
	t_shape *curr_shape;
	t_tuple origin;
	t_tuple origin2;
	t_tuple origin3;
	bool is_hit;
	double tmax;
	t_ray ray;
	t_color color = color_new(0.2, 0.2, 0.8);
	t_hit_record rec;
	origin = tuple_new_point(960.0, 540.0, -1000.0);
	origin2 = tuple_new_point(255.0, 255.0, -1000.0);
	origin3 = tuple_new_point(1255.0, 745.0, -1000.0);
	sphere = shape_new_sphere(origin, 150.0, color);
	sphere2 = shape_new_sphere(origin2, 150.0, color);
	sphere3 = shape_new_sphere(origin3, 150.0, color);
	ft_memset(&rec, 0, sizeof(t_hit_record));
	vector_pushback(&vector, &sphere);
	vector_pushback(&vector, &sphere2);
	vector_pushback(&vector, &sphere3);
	vector_iterator_begin(&it, &vector);
	for (uint32_t i = 0; i < canvas.width; i++) {
		for (uint32_t j = 0; j < canvas.height; j++) {
			tmax = M_INFINITY;
			is_hit = false;
			ray = (t_ray) {tuple_new_point(i, j, 0.0), tuple_new_vector(0, 0, -1)};
			it.index = 0;
			while (!it.end(&it)) {
				curr_shape = (t_shape *) it.get(&it);
				rec.shape = curr_shape;
				if (curr_shape->vtable.hit(ray, .00001, tmax, &rec)) {
					tmax = rec.t;
					is_hit = true;
				}
				if (is_hit)
					image_set_pixel(canvas, rec.color, i, j);
				else
					image_set_pixel(canvas, color_new(0.2, 0.2, 0.2), i, j);
				it.next(&it);
			}
		}
	}
}

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

void	projectile_test(t_image canvas)
{
	t_projectile p = (t_projectile) {tuple_new_point(0.0, 1.0, 0.0), tuple_normalize(tuple_new_vector(0.8, 1, 0.0))};
	t_environment e = (t_environment) {tuple_new_vector(0, -0.1, 0), tuple_new_vector(-0.01, 0, 0)};
	p.velocity = tuple_multiply_s(p.velocity, 17.0);

	while (p.position.y >= 0)
	{
		if (p.position.x > canvas.width || (canvas.height - p.position.y) <= 0)
			break ;
		image_set_pixel(canvas, color_new(1.0, 0.0, 0.0),p.position.x , canvas.height - p.position.y);
		p = tick(p, e);
	}
}

int main(void) {
	t_window	window;
	t_image		canvas;
	t_matrix	matrix;
	t_matrix	matrix2;

	run_tests();
	matrix = matrix_init(2, 2);

	window_create(&window, 1920, 1080);
	window_add_image(window.mlx, &canvas);
	matrix = matrix_init(4, 4);
	matrix2 = matrix_init(4, 4);

	matrix_set(matrix, 0, 0, 1);
	matrix_set(matrix, 0, 1, 2);
	matrix_set(matrix, 0, 2, 3);
	matrix_set(matrix, 0, 3, 4);

	matrix_set(matrix, 1, 0, 5);
	matrix_set(matrix, 1, 1, 6);
	matrix_set(matrix, 1, 2, 7);
	matrix_set(matrix, 1, 3, 8);

	matrix_set(matrix, 2, 0, 9);
	matrix_set(matrix, 2, 1, 8);
	matrix_set(matrix, 2, 2, 7);
	matrix_set(matrix, 2, 3, 6);

	matrix_set(matrix, 3, 0, 5);
	matrix_set(matrix, 3, 1, 4);
	matrix_set(matrix, 3, 2, 3);
	matrix_set(matrix, 3, 3, 2);


	matrix_set(matrix2, 0, 0, -2);
	matrix_set(matrix2, 0, 1, 1);
	matrix_set(matrix2, 0, 2, 2);
	matrix_set(matrix2, 0, 3, 3);

	matrix_set(matrix2, 1, 0, 3);
	matrix_set(matrix2, 1, 1, 2);
	matrix_set(matrix2, 1, 2, 1);
	matrix_set(matrix2, 1, 3, -1);

	matrix_set(matrix2, 2, 0, 4);
	matrix_set(matrix2, 2, 1, 3);
	matrix_set(matrix2, 2, 2, 6);
	matrix_set(matrix2, 2, 3, 5);

	matrix_set(matrix2, 3, 0, 1);
	matrix_set(matrix2, 3, 1, 2);
	matrix_set(matrix2, 3, 2, 7);
	matrix_set(matrix2, 3, 3, 8);

	matrix_inverse(matrix);
//	projectile_test(canvas);
//	run_sphere_test(canvas);
	window_draw_loop(window.mlx);
	return (0);
}