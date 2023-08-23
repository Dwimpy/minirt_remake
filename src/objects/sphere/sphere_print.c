/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:55:28 by arobu             #+#    #+#             */
/*   Updated: 2023/08/07 19:06:29 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "shape.h"
#include "sphere.h"

void	sphere_print(t_shape *shape)
{
	t_sphere	*sphere;

	sphere = shape_get_data(shape);
	printf("Sphere: \n");
	printf("%f\t", sphere->radius);
	tuple_print(matrix_multiply_tuple(shape->transform.tf, sphere->origin));
	printf("----------------------\n");
}
