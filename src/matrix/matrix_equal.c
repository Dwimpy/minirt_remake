/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_equal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 01:53:31 by arobu             #+#    #+#             */
/*   Updated: 2023/07/31 01:53:31 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "vec3.h"

bool	matrix_equal(t_matrix a, t_matrix b)
{
	int		row;
	int		col;
	double	a_val;
	double	b_val;

	if (a.dimension != b.dimension)
		return (false);
	row = 1;
	while ((row - 1) < a.dimension)
	{
		col = 1;
		a_val = matrix_get_element_at(a, row, col);
		while ((col - 1) < a.dimension)
		{
			b_val =  matrix_get_element_at(b, row, col);
			if (is_approx_equal(a_val, b_val, M_EPSILON))
				return (false);
			col++;
		}
		row++;
	}
	return (true);
}