/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_rotate_z.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:35:08 by arobu             #+#    #+#             */
/*   Updated: 2023/08/14 14:35:08 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

inline void	shape_rotate_z(t_shape *shape, double z)
{
	tf_rotate_z(&shape->transform, z);
}
