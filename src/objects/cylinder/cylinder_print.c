/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:42:38 by arobu             #+#    #+#             */
/*   Updated: 2023/08/12 15:42:38 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

void	cylinder_print(t_shape *shape)
{
	t_cylinder	*cylinder;

	cylinder = shape_get_data(shape);
	printf("---------------------");
	printf("Cylinder Origin: ");
	tuple_print(matrix_multiply_tuple(shape->transform.tf, cylinder->origin));
	printf("---------------------");
}
