/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 18:46:24 by arobu             #+#    #+#             */
/*   Updated: 2023/08/12 18:46:24 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disk.h"
#include "vector.h"

t_shape	shape_new_disk(void)
{
	t_shape	shape;
	t_disk	*disk;

	disk = ft_calloc(1, sizeof(t_disk));
	if (!disk)
	{
		write(2, DISK_MEM_ALLOCATION_FAILED, 41);
		exit(EXIT_FAILURE);
	}
	shape.transform = tf_new();
	disk->origin = tuple_new_point(0, 0, 0);
	disk->normal = tuple_new_vector(0, 1, 0);
	shape.data = disk;
	shape.transform.inv_tf = matrix_identity();
	shape.transform.tf_transpose = matrix_identity();
	shape.transform.inv_tf_transpose = matrix_identity();
	shape.vtable.intersect = disk_intersect;
	shape.vtable.normal_at = disk_normal_at;
	shape.vtable.print = disk_print;
	return (shape);
}