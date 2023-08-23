/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_scale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:30:55 by arobu             #+#    #+#             */
/*   Updated: 2023/08/14 14:30:55 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

inline void	shape_scale(t_shape *shape, double x, double y, double z)
{
	tf_scale(&shape->transform, x, y, z);
}
