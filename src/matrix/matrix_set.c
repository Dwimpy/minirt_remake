/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 01:25:20 by arobu             #+#    #+#             */
/*   Updated: 2023/07/31 01:25:20 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "stdbool.h"
#include "matrix_internal.h"

void	matrix_set(t_matrix mtx, int row, int column, double value)
{
	if (is_elem_out_of_range(row, column, mtx.dimension))
	{
		write(2, ERR_MTX_OUT_OF_RANGE, 35);
		exit (EXIT_FAILURE);
	}
	mtx.matrix[(row - 1) * mtx.dimension + (column - 1)] = value;
}

