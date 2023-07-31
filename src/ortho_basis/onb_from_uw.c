/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onb_from_wu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:13:31 by arobu             #+#    #+#             */
/*   Updated: 2023/07/31 19:13:31 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "onb.h"

t_onb	onb_init_from_uw(t_vec3 u, t_vec3 w)
{
	t_onb	onb;

	onb.u = vec3_normalize(u);
	onb.v = vec3_normalize(vec3_cross(w, u));
	onb.w = vec3_cross(onb.u, onb.v);
	return (onb);
}

t_onb	onb_init_from_wu(t_vec3 w, t_vec3 u)
{
	t_onb	onb;

	onb.w = vec3_normalize(w);
	onb.v = vec3_normalize(vec3_cross(w, u));
	onb.u = vec3_cross(onb.v, onb.w);
	return (onb);
}