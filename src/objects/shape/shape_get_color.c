/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_get_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:40:20 by arobu             #+#    #+#             */
/*   Updated: 2023/08/07 15:40:20 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

inline t_color	shape_get_color(const t_shape *shape)
{
	return (shape->material.color);
}
