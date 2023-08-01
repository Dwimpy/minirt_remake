/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onb_from_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:11:40 by arobu             #+#    #+#             */
/*   Updated: 2023/07/31 19:11:40 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "onb.h"
#include "tuple.h"

t_onb onb_init_from_u(t_tuple u) {
	t_onb	onb;
	t_tuple	x_axis;
	t_tuple	y_axis;

	x_axis = tuple_new_vector(1.0, 0.0, 0.0);
	y_axis = tuple_new_vector(0.0, 1.0, 0.0);
	onb.u = tuple_normalize(u);
	onb.v = tuple_cross(onb.u, x_axis);
	if (tuple_magnitude(onb.v) < ONB_EPSILON)
		onb.v = tuple_cross(onb.u, y_axis);
	onb.w = tuple_cross(onb.u, onb.v);
	return (onb);
}
