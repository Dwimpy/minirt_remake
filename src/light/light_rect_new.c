/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_rect_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:30:56 by arobu             #+#    #+#             */
/*   Updated: 2023/09/16 14:38:49 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "libft.h"
#include "light.h"
#include "tuple.h"

static t_coord	light_construct_uv(t_light *light, t_coord width_height);

t_light	light_rect_new(t_rect_light_params p)
{
	t_light			light;
	t_rect_light	*rect_light;

	rect_light = (t_rect_light *) ft_calloc(1, sizeof(t_rect_light));
	if (!rect_light)
	{
		write(2, "Rect light mem alloc failed\n", 28);
		exit(1);
	}
	p.normal = tuple_normalize(p.normal);
	light.type = RECT_LIGHT;
	light.origin = p.origin;
	light.intensity = p.intensity;
	light.data = rect_light;
	rect_light->up = tuple_new_vector(0, 1, 0);
	rect_light->right = tuple_normalize(tuple_cross(p.normal, rect_light->up));
	if (tuple_equal(rect_light->right, tuple_new_vector(0, 0, 0)))
		rect_light->right = tuple_normalize(\
			tuple_cross(tuple_new_vector(1, 0, 0), p.normal));
	light.samples = p.samples;
	rect_light->up = tuple_normalize(tuple_cross(rect_light->right, p.normal));
	rect_light->corner = tuple_subtract(light.origin, \
		tuple_add(tuple_multiply_s(rect_light->up, 0.5 * p.width_height.y), \
			tuple_multiply_s(rect_light->right, 0.5 * p.width_height.x)));
	rect_light->uv = light_construct_uv(&light, p.width_height);
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