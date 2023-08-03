/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:14:40 by arobu             #+#    #+#             */
/*   Updated: 2023/08/01 15:14:40 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"
#include "intersect.h"
#include "libft.h"
#include "matrix.h"
#include "ray.h"
#include "shape.h"
#include "tuple.h"
#include "vector.h"

t_shape shape_new_sphere(t_tuple origin, t_real radius, t_color color) {
	t_shape shape;
	t_sphere *sphere;

	sphere = ft_calloc(1, sizeof(t_sphere));
	if (!sphere) {
		write(2, SPHERE_MEM_ALLOCATION_FAILED, 41);
		exit(EXIT_FAILURE);
	}
	sphere->origin = origin;
	sphere->radius = radius;
	sphere->color = color;
	shape.data = sphere;
	shape.transform.tf = matrix_identity();
	shape.transform.inv_tf = matrix_identity();
	shape.vtable.print = sphere_print;
	shape.vtable.get_data = get_sphere_data;
	shape.vtable.intersect = sphere_intersect;
	shape.vtable.get_color = get_sphere_color;
//	shape.vtable.shadow_hit = sphere_shadow_hit;
	return (shape);
}

void *get_sphere_data(t_shape *shape) {
	return (shape->data);
}

void sphere_print(t_shape *shape) {
	t_sphere *sphere;

	sphere = shape->vtable.get_data(shape);
	printf("%f\t ", sphere->radius);
	tuple_print(sphere->origin);
}

t_color	get_sphere_color(t_shape *shape)
{
	t_sphere	*sphere;

	sphere = shape->vtable.get_data(shape);
	return (sphere->color);
}

bool sphere_intersect(t_shape *shape, t_ray ray, t_vector *intersections) {
	t_tuple sph_to_ray;
	t_sphere *sphere;
	t_quadratic params;
	t_intersect intersect;
	double t1;
	double t2;

	intersect.count = 0;
	sphere = (t_sphere *) shape->data;
	ray = ray_transform(ray, shape->transform);
	sph_to_ray = tuple_subtract(ray.origin, sphere->origin);
	params.a = tuple_dot(ray.direction, ray.direction);
	params.b = 2 * tuple_dot(ray.direction, sph_to_ray);
	params.c = tuple_dot(sph_to_ray, sph_to_ray) - sphere->radius * sphere->radius;
	params.disc = params.b * params.b - 4 * params.a * params.c;
	if (params.disc < 0)
		return (false);
	t1 = (-params.b - sqrt(params.disc)) / (2 * params.a);
	t2 = (-params.b + sqrt(params.disc)) / (2 * params.a);
	if (t1 < t2) {
		intersect.t[0] = t1;
		intersect.t[1] = t2;
	} else {
		intersect.t[0] = t2;
		intersect.t[1] = t1;
	}
	if (t1 != t2)
		intersect.count = 2;
	else
		intersect.count = 1;
	intersect.obj = shape;
	vector_pushback(intersections, &intersect);
	return (true);
}
