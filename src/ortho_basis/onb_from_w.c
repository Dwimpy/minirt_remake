/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onb_from_w.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:11:40 by arobu             #+#    #+#             */
/*   Updated: 2023/07/31 19:11:40 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "onb.h"

t_onb onb_init_from_w(t_tuple w) {
	t_onb	onb;
	t_tuple	x_axis;
	t_tuple	y_axis;

	x_axis = tuple_new_vector(1.0, 0.0, 0.0);
	y_axis = tuple_new_vector(0.0, 1.0, 0.0);
	onb.w = tuple_normalize(w);
	onb.u = tuple_cross(onb.w, x_axis);
	if (tuple_magnitude(onb.u) < ONB_EPSILON)
		onb.v = tuple_cross(onb.w, y_axis);
	onb.v = tuple_cross(onb.w, onb.u);
	return (onb);
}