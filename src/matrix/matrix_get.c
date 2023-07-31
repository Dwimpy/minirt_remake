/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 01:42:52 by arobu             #+#    #+#             */
/*   Updated: 2023/07/31 01:42:52 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "matrix_internal.h"

double	matrix_get(t_matrix mtx, int row, int column)
{
	if (is_elem_out_of_range(row, column, mtx.dimension))
	{
		write(2, ERR_MTX_OUT_OF_RANGE, 35);
		exit (EXIT_FAILURE);
	}
	return (mtx.matrix[(row - 1) * mtx.dimension + (column - 1)]);
}