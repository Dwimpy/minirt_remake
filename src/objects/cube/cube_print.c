/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 22:29:46 by arobu             #+#    #+#             */
/*   Updated: 2023/08/23 16:35:24 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	cube_print(t_shape *shape)
{
	t_cube	*cube;

	cube = shape_get_data(shape);
	printf("---------------------\n");
	printf("Cube Origin: ");
	matrix_print(shape->transform.tf);
	tuple_print(matrix_multiply_tuple(shape->transform.tf, cube->origin));
	printf("---------------------\n");
}
