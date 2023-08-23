/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_transform_reset.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:54:14 by arobu             #+#    #+#             */
/*   Updated: 2023/08/14 15:54:14 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

void	shape_reset(t_shape *shape)
{
	matrix_identity(&shape->transform.translation);
	matrix_identity(&shape->transform.rotation);
	matrix_identity(&shape->transform.scaling);
	matrix_identity(&shape->transform.tf);
	matrix_identity(&shape->transform.inv_tf);
	matrix_identity(&shape->transform.inv_tf_transpose);
}
