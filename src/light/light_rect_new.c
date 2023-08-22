/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_rect_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:30:56 by arobu             #+#    #+#             */
/*   Updated: 2023/08/21 13:56:36 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "libft.h"
#include "light.h"
#include "tuple.h"

static t_coord	light_construct_uv(t_light *light, t_coord width_height);

t_light	light_rect_new(t_tuple origin, t_color intensity, t_tuple normal, t_coord width_height, size_t samples)
{
	t_light			light;
	t_rect_light	*rect_light;

	rect_light = (t_rect_light *) ft_calloc(1, sizeof(t_rect_light));
	if (!rect_light)
	{
		write(2, "Rect light mem alloc failed\n", 28);
		exit(1);
	}
	normal = tuple_normalize(normal);
	light.type = RECT_LIGHT;
	light.origin = origin;
	light.intensity = intensity;
	light.data = rect_light;
	rect_light->up = tuple_new_vector(0, 1, 0);
	rect_light->right = tuple_normalize(tuple_cross(normal, rect_light->up));
	if (tuple_equal(rect_light->right, tuple_new_vector(0, 0, 0)))
		rect_light->right = tuple_normalize(tuple_cross(tuple_new_vector(1, 0, 0), normal));
	light.samples = samples;
	rect_light->up = tuple_normalize(tuple_cross(rect_light->right, normal));
	rect_light->corner = tuple_subtract(light.origin, tuple_add(tuple_multiply_s(rect_light->up, 0.5 * width_height.y),
														   tuple_multiply_s(rect_light->right, 0.5 * width_height.x)));
	rect_light->uv = light_construct_uv(&light, width_height);
	return (light);
}

static t_coord	light_construct_uv(t_light *light, t_coord width_height)
{
	t_tuple			normalized_normal;
	t_tuple			adjusted_point;
	t_coord			coord;
	t_rect_light	*rect_light;

	rect_light = light->data;
	coord.x = width_height.x / (t_real)(light->samples);
	coord.y = width_height.y / (t_real)(light->samples);
	return (coord);
}