/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_intersection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 21:32:24 by arobu             #+#    #+#             */
/*   Updated: 2023/08/08 21:32:24 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"

t_intersect	intersection(t_real t, t_shape *shape)
{
	t_intersect isect;

	isect.t = t;
	isect.obj = shape;
	return (isect);
}