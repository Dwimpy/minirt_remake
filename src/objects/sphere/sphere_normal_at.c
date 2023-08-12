/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_normal_at.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:47:03 by arobu             #+#    #+#             */
/*   Updated: 2023/08/07 15:47:03 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "sphere.h"
#include "transform.h"
#include "tuple.h"

inline static \
	t_tuple	sphere_local_normal_at(t_shape *shape, t_tuple isec_point);

t_tuple	sphere_normal_at(t_shape *shape, t_tuple isec_point)
{
	return (sphere_local_normal_at(shape, isec_point));
}

inline static \
	t_tuple	sphere_local_normal_at(t_shape *shape, t_tuple isec_point)
{
	t_transform	*tf;
	t_tuple		local_point;
	t_tuple		local_normal;
	t_tuple		world_normal;

	tf = &shape->transform;
	local_point = matrix_multiply_tuple(tf->inv_tf, isec_point);
	local_normal = tuple_subtract(local_point, tuple_new_point(0, 0, 0));
	world_normal = matrix_multiply_tuple(tf->inv_tf_transpose, local_normal);
	return (tuple_normalize(world_normal));
}