/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:25:01 by arobu             #+#    #+#             */
/*   Updated: 2023/07/30 19:25:01 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

inline t_real clamp(t_real n, double min, double max)
{
	if (n < min)
		return (min);
	else if (n > max)
		return (max);
	return (n);
}

inline t_tuple	tuple_clamp(t_tuple v, double min, double max)
{
	t_tuple	clamped;

	clamped.x = clamp(v.x, min, max);
	clamped.y = clamp(v.y, min, max);
	clamped.z = clamp(v.z, min, max);
	return (clamped);
}