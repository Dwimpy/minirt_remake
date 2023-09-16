/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_intensity_at.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:47:46 by arobu             #+#    #+#             */
/*   Updated: 2023/09/16 14:31:45 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "light.h"

static double	inline	light_intensity_at_point_light(\
	t_scene *world, t_light *light, t_tuple *point, t_thread_isect *isect);
static double	inline	light_intensity_at_rect_light(\
	t_scene *world, t_light *light, t_tuple *point, t_thread_isect *isect);

t_real	light_intensity_at_threads(\
	t_scene *world, t_light *light, t_tuple *point, t_thread_isect *isect)
{
	if (light->type == POINT_LIGHT)
		return (light_intensity_at_point_light(world, light, point, isect));
	else
		return (light_intensity_at_rect_light(world, light, point, isect));
}

static double inline	light_intensity_at_point_light(\
	t_scene *world, t_light *light, t_tuple *point, t_thread_isect *isect)
{
	if (intersect_shadow_hit_threads(world, &light->origin, point, isect))
		return (0.0);
	return (1.0);
}

static double inline	light_intensity_at_rect_light(\
	t_scene *world, t_light *light, t_tuple *point, t_thread_isect *isect)
{
	size_t		i;
	size_t		j;
	t_tuple		light_pos;
	t_real		total;

	i = 0;
	total = 0.0;
	while (i < light->samples)
	{
		j = 0;
		while (j < light->samples)
		{
			light_pos = light_point_on(light, i, j);
			if (!intersect_shadow_hit_threads(world, &light_pos, point, isect))
				total += 1.0;
			j++;
		}
		i++;
	}
	return (total / ((t_real)light->samples * (t_real)light->samples));
}
