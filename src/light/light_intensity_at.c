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
	if (intersect_shadow_hit(world, &light->origin, point))
		return (0.0);
	return (1.0);
}