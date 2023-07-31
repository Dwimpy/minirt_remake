/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onb_from_v.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:11:40 by arobu             #+#    #+#             */
/*   Updated: 2023/07/31 19:11:40 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "onb.h"

t_onb onb_init_from_v(t_vec3 v) {
	t_onb	onb;
	t_vec3	x_axis;
	t_vec3	y_axis;

	x_axis = vec3_create(1.0, 0.0, 0.0);
	y_axis = vec3_create(0.0, 1.0, 0.0);
	onb.v = vec3_normalize(v);
	onb.u = vec3_cross(onb.v, x_axis);
	if (vec3_magnitude(onb.u) < ONB_EPSILON)
		onb.v = vec3_cross(onb.v, y_axis);
	onb.w = vec3_cross(onb.u, onb.v);
	return (onb);
}