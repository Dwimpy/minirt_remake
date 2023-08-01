/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:04:02 by arobu             #+#    #+#             */
/*   Updated: 2023/07/30 19:04:02 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

inline bool	tuple_equal(t_tuple v, t_tuple res)
{
	if (!is_approx_equal(v.x, res.x, M_EPSILON) || \
	!is_approx_equal(v.y, res.y, M_EPSILON) || \
	!is_approx_equal(v.z, res.z, M_EPSILON))
		return (false);
	return (true);
}

inline bool	tuple_equal_s(t_tuple v, t_real s)
{
	if (!is_approx_equal(v.x, s, M_EPSILON) || \
	!is_approx_equal(v.y, s, M_EPSILON) || \
	!is_approx_equal(v.z, s, M_EPSILON))
		return (false);
	return (true);
}