/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_set_normal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:35:36 by arobu             #+#    #+#             */
/*   Updated: 2023/08/05 19:35:36 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "tuple.h"

void	intersect_set_normal(t_computations *comps)
{
	if (tuple_dot(comps->normal, comps->eye) < 0)
	{
		comps->normal = tuple_negate(comps->normal);
		comps->inside = true;
	}
	else
		comps->inside = false;
}