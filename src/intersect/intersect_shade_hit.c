/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_shade_hit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:59:36 by arobu             #+#    #+#             */
/*   Updated: 2023/08/06 14:59:36 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "light.h"

t_color	intersect_shade_hit(t_vector *world, t_light *light, t_computations *comps)
{
	intersect_is_shadowed(world, light, comps);
	return (light_lightning(light, comps));
}