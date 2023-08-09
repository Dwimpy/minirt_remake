/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_color_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:21:24 by arobu             #+#    #+#             */
/*   Updated: 2023/08/09 21:21:24 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "intersect.h"
#include "scene.h"

t_color	intersect_color_at(t_scene *world, t_ray *ray)
{
	t_intersect *i;

	intersect_world(world, ray);
	i = intersect_hit(&world->intersections);
	if (i)
	{
		intersect_compute(i, ray, &world->comps);
		return (intersect_shade_hit(world, &world->comps));
	}
	return (color_new(0, 0, 0));
}