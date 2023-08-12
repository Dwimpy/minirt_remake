/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 19:49:06 by arobu             #+#    #+#             */
/*   Updated: 2023/08/12 19:49:06 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disk.h"

void	disk_print(t_shape *shape)
{
	t_disk	*disk;

	disk = shape_get_data(shape);
	printf("Disk: \n");
	tuple_print(matrix_multiply_tuple(shape->transform.tf, disk->origin));
	tuple_print(matrix_multiply_tuple(shape->transform.tf, disk->normal));
	printf("----------------------\n");
}