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

#include "intersect.h"
#include "light.h"
#include "shape.h"
#include "scene.h"

t_color intersect_shade_hit(t_scene *world, t_computations *comps)
{
	return (light_lightning(comps, &world->light));
}