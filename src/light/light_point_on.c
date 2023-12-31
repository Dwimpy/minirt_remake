/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_point_on.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:31:12 by arobu             #+#    #+#             */
/*   Updated: 2023/08/23 14:32:33 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "rng.h"

t_tuple	light_point_on(t_light *light, size_t x, size_t y)
{
	t_rect_light	*data;

	data = light->data;
	return (tuple_add(data->corner, \
		tuple_add(tuple_multiply_s(\
			data->up, ((t_real)y + random_double()) * data->uv.y), \
		tuple_multiply_s(\
			data->right, ((t_real)x + random_double()) * data->uv.x))));
}
