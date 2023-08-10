/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_shade_hit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:07:57 by arobu             #+#    #+#             */
/*   Updated: 2023/08/09 20:07:57 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "intersect.h"
#include "light.h"
#include "shape.h"
#include "scene.h"
#include "tuple.h"

t_color intersect_shade_hit(t_scene *world, t_computations *comps, int depth)
{
	t_color	surface_color;
	t_color	reflected_color;

	comps->is_shadowed = intersect_shadow_hit(world, &comps->over_point);
	surface_color = light_lightning(comps, &world->light);
	reflected_color = intersect_reflected_color(world, &world->comps, depth);
	return (tuple_add(surface_color, reflected_color));
}