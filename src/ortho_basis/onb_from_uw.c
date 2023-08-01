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

t_onb	onb_init_from_uw(t_tuple u, t_tuple w)
{
	t_onb	onb;

	onb.u = tuple_normalize(u);
	onb.v = tuple_normalize(tuple_cross(w, u));
	onb.w = tuple_cross(onb.u, onb.v);
	return (onb);
}

t_onb	onb_init_from_wu(t_tuple w, t_tuple u)
{
	t_onb	onb;

	onb.w = tuple_normalize(w);
	onb.v = tuple_normalize(tuple_cross(w, u));
	onb.u = tuple_cross(onb.v, onb.w);
	return (onb);
}