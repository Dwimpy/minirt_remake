/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_multiply_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:32:04 by arobu             #+#    #+#             */
/*   Updated: 2023/07/30 18:32:04 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

inline t_tuple	tuple_multiply(t_tuple v1, t_tuple v2)
{
	return ((t_tuple){v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w});
}

inline t_tuple	tuple_multiply_s(t_tuple v, t_real s)
{
	return ((t_tuple){v.x * s, v.y * s, v.z * s, v.w * s});
}
