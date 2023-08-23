/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:53:40 by arobu             #+#    #+#             */
/*   Updated: 2023/07/30 18:53:40 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

inline t_tuple	tuple_normalize(t_tuple v)
{
	t_real	len;

	len = tuple_magnitude(v);
	if (is_approx_equal(len, 0, M_EPSILON))
		return (tuple_vector_zero());
	return ((t_tuple){v.x / len, v.y / len, v.z / len, v.w / len});
}
