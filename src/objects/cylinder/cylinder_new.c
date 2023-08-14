/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:35:19 by arobu             #+#    #+#             */
/*   Updated: 2023/08/12 15:35:19 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

t_shape	shape_new_cylinder(t_real y_min, t_real y_max, bool capped)
{
	t_shape		shape;
	t_cylinder	*cylinder;

	cylinder = ft_calloc(1, sizeof(t_cylinder));
	if (!cylinder)
	{
		write(2, CYLINDER_MEM_ALLOCATION_FAILED, 45);
		exit(EXIT_FAILURE);
	}

	shape.transform = tf_new();
	cylinder->origin = tuple_new_point(0, 0, 0);
	cylinder->bounds.y_min = y_min;
	cylinder->bounds.y_max = y_max;
	cylinder->capped = capped;
	shape.data = cylinder;
	shape.vtable.print = cylinder_print;
	shape.vtable.intersect = cylinder_intersect;
	shape.vtable.normal_at = cylinder_normal_at;
	return (shape);
}
