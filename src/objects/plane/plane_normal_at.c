 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_normal_at.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:11:00 by arobu             #+#    #+#             */
/*   Updated: 2023/08/07 19:17:36 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"
#include "tuple.h"

t_tuple	plane_normal_at(t_shape *shape, t_tuple isec_point)
{
	t_transform	*tf;
	t_tuple		local_normal;
	t_tuple		world_normal;

	tf = &shape->transform;
	local_normal = tuple_new_vector(0, -1, 0);
	world_normal = matrix_multiply_tuple(tf->inv_tf_transpose, local_normal);
	world_normal.w = 0;
	return (tuple_normalize(world_normal));
}