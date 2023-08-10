/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:30:17 by arobu             #+#    #+#             */
/*   Updated: 2023/08/08 03:43:44 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "material.h"
#include "sphere.h"

t_shape shape_new_sphere(t_real radius)
{
	t_shape shape;
	t_sphere *sphere;

	sphere = ft_calloc(1, sizeof(t_sphere));
	if (!sphere)
	{
		write(2, SPHERE_MEM_ALLOCATION_FAILED, 43);
		exit(EXIT_FAILURE);
	}
	shape.transform = tf_new();
	sphere->origin = tuple_new_point(0, 0, 0);
	sphere->radius = radius;
	shape.data = sphere;
	shape.id = id;
	shape.transform.inv_tf = matrix_identity();
	shape.transform.tf_transpose = matrix_identity();
	shape.transform.inv_tf_transpose = matrix_identity();
	shape.vtable.print = sphere_print;
	shape.vtable.intersect = sphere_intersect;
	shape.vtable.normal_at = sphere_normal_at;
	id++;
	return (shape);
}
