/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:53:47 by arobu             #+#    #+#             */
/*   Updated: 2023/08/14 19:53:47 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

void	shape_rotate(t_shape *shape, double x, double y, double z)
{
	tf_rotate(&shape->transform, x, y, z);
}
