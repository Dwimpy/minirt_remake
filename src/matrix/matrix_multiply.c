/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 02:02:07 by arobu             #+#    #+#             */
/*   Updated: 2023/07/31 02:02:07 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

static void	matrix_multiply_loop(t_matrix a, t_matrix b, t_matrix mtx);

t_matrix	matrix_multiply(t_matrix a, t_matrix b)
{
	t_matrix	mtx;


	if (a.dimension != b.dimension)
	{
		write(1, ERR_MTX_SAME_DIMENSION, 49);
		exit(EXIT_FAILURE);
	}

	mtx = matrix_init(a.dimension);
	matrix_multiply_loop(a, b, mtx);
	return (mtx);
}

static void	matrix_multiply_loop(t_matrix a, t_matrix b, t_matrix mtx)
{
	int			i;
	int			j;
	int			k;

	i = 0;
	j = 0;
	k = 0;
	while (i < a.dimension)
	{
		j = 0;
		while (j < b.dimension)
		{
			k = 0;
			while (k < a.dimension)
			{
				mtx.matrix[i * mtx.dimension + j] += a.matrix[i * a.dimension + k] * b.matrix[k * b.dimension + j];
				k++;
			}
			j++;
		}
		i++;
	}
}