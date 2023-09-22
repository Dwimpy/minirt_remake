/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk_normal_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 19:49:16 by arobu             #+#    #+#             */
/*   Updated: 2023/08/12 19:49:16 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disk.h"

t_tuple	disk_normal_at(t_shape *shape, t_tuple isec_point)
{
	t_tuple	normal;
	(void)isec_point;

	normal = tuple_new_vector(0, 1, 0);
	normal = matrix_multiply_tuple(shape->transform.inv_tf_transpose, normal);
	normal.w = 0;
	return (tuple_normalize(normal));
}
