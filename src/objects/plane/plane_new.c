/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:49:17 by arobu             #+#    #+#             */
/*   Updated: 2023/08/08 03:43:28 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "plane.h"

t_shape	shape_new_plane(void)
{
	t_shape	shape;
	t_plane	*plane;

	plane = ft_calloc(1, sizeof(t_plane));
	if (!plane)
	{
		write(2, PLANE_MEM_ALLOCATION_FAILED, 42);
		exit(EXIT_FAILURE);
	}
	shape.transform = tf_new();
	plane->origin = tuple_new_point(0, 0, 0);
	plane->normal = tuple_new_vector(0, 1, 0);
	shape.data = plane;
	shape.vtable.intersect = plane_intersect;
	shape.vtable.normal_at = plane_normal_at;
	shape.vtable.print = plane_print;
	return (shape);
}
