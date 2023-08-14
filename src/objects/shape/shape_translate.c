/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:03:31 by arobu             #+#    #+#             */
/*   Updated: 2023/08/01 15:03:31 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "shape.h"
#include "transform.h"

inline void	shape_translate(t_shape *shape, double x, double y, double z)
{
	tf_translate(&shape->transform, x, y, z);
}