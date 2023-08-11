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
#include "vector.h"

t_color	intersect_color_at(t_scene *world, t_ray *ray, int depth)
{
	t_intersect	*i;
	t_color		color;


	color = color_new(0, 0, 0);
	vector_clear(&world->intersections);
	intersect_world(world, ray);
	i = intersect_hit(&world->intersections);
	if (i)
	{
		intersect_compute(i, ray, &world->comps, &world->intersections);
		color = intersect_shade_hit(world, &world->comps, depth);
	}
	return (color);
}