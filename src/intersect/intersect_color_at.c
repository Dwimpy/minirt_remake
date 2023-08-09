/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_color_at.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:46:31 by arobu             #+#    #+#             */
/*   Updated: 2023/08/09 05:25:28 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "intersect.h"
#include "light.h"
#include "shape.h"
#include "tuple.h"

t_color	intersect_color_at(\
	t_vector *world, t_ray ray, t_computations *comps, t_light *light, int depth)
{
	t_color	color;

	color = color_new(0, 0, 0);
	vector_clear(&comps->intersections);
	intersect_world(world, ray, &comps->intersections);
	comps->is_shadowed = false;
	if (intersect_hit(&ray, comps))
		return (intersect_shade_hit(world, light, comps, depth));
	return (color);
}
