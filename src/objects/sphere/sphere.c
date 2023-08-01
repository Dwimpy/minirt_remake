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
#include "libft.h"
#include "ray.h"
#include "shape.h"
#include "tuple.h"

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
	shape.vtable.print = sphere_print;
	shape.vtable.get_data = get_sphere_data;
	shape.vtable.hit = sphere_hit;
	shape.vtable.shadow_hit = sphere_shadow_hit;
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

bool sphere_hit(t_ray ray, t_real tmin, t_real tmax, t_hit_record *hit_rec) {
	t_tuple pc;
	double a;
	double b;
	double c;
	t_sphere *sphere;
	sphere = (t_sphere *)hit_rec->shape->vtable.get_data(hit_rec->shape);
	pc = tuple_subtract(ray.origin, sphere->origin);
	a = tuple_dot(ray.direction, ray.direction);
	b = 2 * tuple_dot(ray.direction, pc);
	c = tuple_dot(pc, pc) - sphere->radius * sphere->radius;

	double disc;
	disc = b * b - 4 * a * c;
//	printf("%f\n", disc);
	if (disc > 0) {
		disc = sqrt(disc);
		double t = (-b - disc) / (2 * a);
		if (t < tmin)
			t = (-b + disc) / (2 * a);
		if (t < tmin || t > tmax)
			return (false);
		hit_rec->color = sphere->color;
		hit_rec->t = t;
		hit_rec->normal = tuple_normalize(tuple_subtract(ray_value_at(ray, hit_rec->t), sphere->origin));
		return (true);
	}
	return (false);
}

bool	sphere_shadow_hit(t_ray ray, t_real tmin, t_real tmax, t_hit_record *hit_rec)
{
	return (false);
}