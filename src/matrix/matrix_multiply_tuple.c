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
	t_tuple 	result;
	t_matrix	tmp;
	t_matrix	mult;

	result = tuple_vector_zero();
	tmp = matrix_init(4, 1);
	matrix_set(tmp, 0, 0, t.x);
	matrix_set(tmp, 1, 0, t.y);
	matrix_set(tmp, 2, 0, t.z);
	matrix_set(tmp, 3, 0, t.w);
	mult = matrix_multiply(m, tmp);
	result.x = matrix_get(mult, 0, 0);
	result.y = matrix_get(mult, 1, 0);
	result.z = matrix_get(mult, 2, 0);
	result.w = matrix_get(mult, 3, 0);
	matrix_free(tmp);
	matrix_free(mult);
	return (result);
}
