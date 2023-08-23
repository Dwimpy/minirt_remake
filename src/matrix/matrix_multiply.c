/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 20:56:58 by arobu             #+#    #+#             */
/*   Updated: 2023/08/23 15:12:05 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

inline static void	copy_matrix_elements(t_matrix *result, t_matrix *tmp);
static inline void	matrix_multiply_row(\
	t_matrix *result, t_matrix *m1, t_matrix *m2, size_t row);

inline void	matrix_multiply(t_matrix *result, t_matrix *m1, t_matrix *m2)
{
	t_matrix	tmp;
	size_t		row;

	tmp = matrix_init(4, 4);
	row = 0;
	while (row < 4)
	{
		matrix_multiply_row(&tmp, m1, m2, row);
		++row;
	}
	copy_matrix_elements(result, &tmp);
	matrix_free(tmp);
}

static inline void	matrix_multiply_row(\
	t_matrix *result, t_matrix *m1, t_matrix *m2, size_t row)
{
	size_t	col;
	size_t	i;

	col = 0;
	while (col < 4)
	{
		i = 0;
		result->data[row][col] = 0;
		while (i < 4)
		{
			result->data[row][col] += m1->data[row][i] * m2->data[i][col];
			++i;
		}
		++col;
	}
}

inline static void	copy_matrix_elements(t_matrix *result, t_matrix *tmp)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < tmp->rows)
	{
		j = 0;
		while (j < tmp->cols)
		{
			result->data[i][j] = tmp->data[i][j];
			++j;
		}
		++i;
	}
}
