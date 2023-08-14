/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiply_tuple.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 21:33:09 by arobu             #+#    #+#             */
/*   Updated: 2023/08/01 21:33:09 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "tuple.h"

inline t_tuple matrix_multiply_tuple(t_matrix m, t_tuple t)
{
	t_tuple	result;

	result = tuple_vector_zero();
	result.x = m.data[0][0]*t.x + m.data[0][1]*t.y + m.data[0][2] * t.z + m.data[0][3] * t.w;
	result.y = m.data[1][0]*t.x + m.data[1][1]*t.y + m.data[1][2] * t.z + m.data[1][3] * t.w;
	result.z = m.data[2][0]*t.x + m.data[2][1]*t.y + m.data[2][2] * t.z + m.data[2][3] * t.w;
	result.w = m.data[3][0]*t.x + m.data[3][1]*t.y + m.data[3][2] * t.z + m.data[3][3] * t.w;
	return (result);
}
