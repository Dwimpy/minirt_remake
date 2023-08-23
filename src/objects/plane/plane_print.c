/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:08:26 by arobu             #+#    #+#             */
/*   Updated: 2023/08/07 19:08:26 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"

void	plane_print(t_shape *shape)
{
	t_plane	*plane;

	plane = shape_get_data(shape);
	printf("Plane: \n");
	tuple_print(matrix_multiply_tuple(shape->transform.tf, plane->origin));
	tuple_print(matrix_multiply_tuple(shape->transform.tf, plane->normal));
	printf("----------------------\n");
}
