/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_intensity_at.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:47:46 by arobu             #+#    #+#             */
/*   Updated: 2023/08/18 17:40:56 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "light.h"

t_real	light_intensity_at(t_scene *world, t_light *light, t_tuple *point)
{
	t_real			total;
	size_t			i;
	size_t			j;
	t_tuple			light_pos;

	total = 0.0;
	i = 0;
	if (light->type == POINT_LIGHT)
	{
		if (intersect_shadow_hit(world, &light->origin, point))
			return (0.0);
		return (1.0);
	}
	while (i < light->samples)
	{
		j = 0;
		while (j < light->samples)
		{
			light_pos = light_point_on(light, i, j);
			if (!intersect_shadow_hit(world, &light_pos, point))
				total += 1.0;
			j++;
		}
		i++;
	}
	return (total / ((t_real)light->samples * (t_real)light->samples));
}

t_real	light_intensity_at_threads(t_scene *world, t_light *light, t_tuple *point, t_thread_isect *isect)
{
	t_real			total;
	size_t			i;
	size_t			j;
	t_tuple			light_pos;

	total = 0.0;
	i = 0;
	if (light->type == POINT_LIGHT)
	{
		if (intersect_shadow_hit_threads(world, &light->origin, point, isect))
			return (0.0);
		return (1.0);
	}
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
