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

#include "shape.h"
#include "transform.h"

inline void	shape_set_transform(t_shape *shape, t_transform tf)
{
	tf_free(shape->transform);
	shape->transform = tf;
}