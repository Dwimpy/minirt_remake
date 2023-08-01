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

t_onb	onb_init_from_uv(t_tuple u, t_tuple v)
{
	t_onb	onb;

	onb.u = tuple_normalize(u);
	onb.w = tuple_normalize(tuple_cross(u, v));
	onb.v = tuple_cross(onb.w, onb.u);
	return (onb);
}

t_onb	onb_init_from_vu(t_tuple v, t_tuple u)
{
	t_onb	onb;

	onb.v = tuple_normalize(v);
	onb.w = tuple_normalize(tuple_cross(u, v));
	onb.u = tuple_cross(onb.v, onb.w);
	return (onb);
}