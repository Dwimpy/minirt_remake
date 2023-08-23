/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 20:33:07 by arobu             #+#    #+#             */
/*   Updated: 2023/08/01 20:33:07 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

inline void	matrix_set(t_matrix m, size_t row, size_t col, double value)
{
	if (row >= m.rows || col >= m.cols)
	{
		write(2, ERR_MTX_OUT_OF_RANGE, 35);
		exit(EXIT_FAILURE);
	}
	m.data[row][col] = value;
}
