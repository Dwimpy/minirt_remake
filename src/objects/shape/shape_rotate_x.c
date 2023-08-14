/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:30:55 by arobu             #+#    #+#             */
/*   Updated: 2023/08/14 14:30:55 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "transform.h"
#include "vector.h"

inline void	shape_rotate_x(t_shape *shape, double x)
{
	tf_rotate_x(&shape->transform, x);
}