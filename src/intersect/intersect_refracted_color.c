/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_refracted_color.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:42:21 by arobu             #+#    #+#             */
/*   Updated: 2023/08/10 22:42:21 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "intersect.h"
#include "tuple.h"
#include "vector.h"

t_color intersect_refracted_color(t_scene *world, t_computations *comps, int depth)
{
	t_real n_ratio;
	t_real cosi;
	t_real sin2t;
	t_real cos_t;
	t_tuple direction;

	n_ratio = comps->n1 / comps->n2;
	cosi = tuple_dot(comps->eye, comps->normal);
	sin2t = n_ratio * n_ratio * (1 - cosi * cosi);
	if (sin2t > 1.0)
		return (color_new(0, 0, 0));
	cos_t = sqrt(1.0 - sin2t);
	direction = tuple_subtract(tuple_multiply_s(comps->normal, n_ratio * cosi - cosi), \
        tuple_multiply_s(comps->eye, n_ratio));

}