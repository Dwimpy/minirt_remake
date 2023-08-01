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

t_onb	onb_init_from_vw(t_tuple v, t_tuple w)
{
	t_onb	onb;

	onb.v = tuple_normalize(v);
	onb.u = tuple_normalize(tuple_cross(v, w));
	onb.w = tuple_cross(onb.u, onb.v);
	return (onb);
}

t_onb	onb_init_from_wv(t_tuple w, t_tuple v)
{
	t_onb	onb;

	onb.w = tuple_normalize(w);
	onb.u = tuple_normalize(tuple_cross(v, w));
	onb.v = tuple_cross(onb.w, onb.u);
	return (onb);
}