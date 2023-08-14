/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:29:54 by arobu             #+#    #+#             */
/*   Updated: 2023/08/11 21:29:54 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "vector.h"

t_shape	shape_new_cube(void)
{
	t_shape		shape;
	t_cube		*cube;

	cube = ft_calloc(1, sizeof(t_cube));
	if (!cube)
	{
		write(2, CUBE_MEM_ALLOCATION_FAILED, 43);
		exit(EXIT_FAILURE);
	}
	shape.transform = tf_new();
	cube->origin = tuple_new_point(0, 0, 0);
	shape.data = cube;
	shape.vtable.print = cube_print;
	shape.vtable.intersect = cube_intersect;
	shape.vtable.normal_at = cube_normal_at;
	return (shape);
}
