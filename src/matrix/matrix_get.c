/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 20:36:15 by arobu             #+#    #+#             */
/*   Updated: 2023/08/01 20:36:15 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

double	matrix_get(t_matrix m, size_t row, size_t col)
{
	if (row >= m.rows || col >= m.cols)
	{
		write(2, ERR_MTX_OUT_OF_RANGE, 36);
		exit (EXIT_FAILURE);
	}
	return (m.data[row][col]);
}