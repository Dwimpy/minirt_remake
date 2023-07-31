/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onb_from_uv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:13:31 by arobu             #+#    #+#             */
/*   Updated: 2023/07/31 19:13:31 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "onb.h"

t_onb	onb_init_from_uv(t_vec3 u, t_vec3 v)
{
	t_onb	onb;

	onb.u = vec3_normalize(u);
	onb.w = vec3_normalize(vec3_cross(u, v));
	onb.v = vec3_cross(onb.w, onb.u);
	return (onb);
}

t_onb	onb_init_from_vu(t_vec3 v, t_vec3 u)
{
	t_onb	onb;

	onb.v = vec3_normalize(v);
	onb.w = vec3_normalize(vec3_cross(u, v));
	onb.u = vec3_cross(onb.v, onb.w);
	return (onb);
}