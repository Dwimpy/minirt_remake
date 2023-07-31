/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onb_from_vw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:13:31 by arobu             #+#    #+#             */
/*   Updated: 2023/07/31 19:13:31 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "onb.h"

t_onb	onb_init_from_vw(t_vec3 v, t_vec3 w)
{
	t_onb	onb;

	onb.v = vec3_normalize(v);
	onb.u = vec3_normalize(vec3_cross(v, w));
	onb.w = vec3_cross(onb.u, onb.v);
	return (onb);
}

t_onb	onb_init_from_wv(t_vec3 w, t_vec3 v)
{
	t_onb	onb;

	onb.w = vec3_normalize(w);
	onb.u = vec3_normalize(vec3_cross(v, w));
	onb.v = vec3_cross(onb.w, onb.u);
	return (onb);
}