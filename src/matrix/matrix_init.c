/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:09:17 by arobu             #+#    #+#             */
/*   Updated: 2023/08/08 03:33:13 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "matrix.h"
#include <stdint.h>

inline t_matrix	matrix_init(size_t rows, size_t cols)
{
	t_matrix	matrix;
	size_t		i;

	i = 0;
	matrix.data = (t_real **)malloc(rows * cols * sizeof(t_real ) + (rows * sizeof(t_real *)));
	matrix.rows = rows;
	matrix.cols = cols;
	matrix.data[0] = (t_real *)(matrix.data + rows);
	while (++i < rows)
		matrix.data[i] = matrix.data[i - 1] + cols;
	i = 0;
	matrix_identity(&matrix);
	return (matrix);
}
