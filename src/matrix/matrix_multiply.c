/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 20:56:58 by arobu             #+#    #+#             */
/*   Updated: 2023/08/01 20:56:58 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

static void matrix_multiply_loop(t_matrix *result, t_matrix m1, t_matrix m2);

t_matrix matrix_multiply(t_matrix m1, t_matrix m2)
{
	t_matrix	result;
	double		sum;

	if (m1.cols != m2.rows)
	{
		write(2, ERR_MTX_SAME_DIMENSION, 51);
		exit(EXIT_FAILURE);
	}
	result = matrix_init(m1.rows, m2.cols);
	matrix_multiply_loop(&result, m1, m2);
	return (result);
}

static void matrix_multiply_loop(t_matrix *result, t_matrix m1, t_matrix m2)
{
	size_t		i;
	size_t		j;
	size_t		k;
	double		sum;

	i = 0;
	while (i < m1.rows)
	{
		j = 0;
		while (j < m2.cols)
		{
			k = 0;
			sum = 0.0;
			while (k < m1.rows)
			{
				sum += m1.data[i][k] * m2.data[k][j];
				k++;
			}
			result->data[i][j] = sum;
			j++;
		}
		i++;
	}
}