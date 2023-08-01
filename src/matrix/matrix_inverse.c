/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 22:51:13 by arobu             #+#    #+#             */
/*   Updated: 2023/08/01 22:51:13 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <sys/_types/_size_t.h>

static void compute_upper_triangular_matrix(t_matrix *lu, t_matrix m);

t_matrix	matrix_inverse(t_matrix m)
{
	t_matrix	lu_decomp_matrix;

	lu_decomp_matrix = matrix_init(m.rows, m.rows);
	compute_upper_triangular_matrix(&lu_decomp_matrix, m);
	matrix_print(lu_decomp_matrix);
	return (lu_decomp_matrix);
}

static void compute_upper_triangular_matrix(t_matrix *lu, t_matrix m)
{
	size_t	i;
	size_t	j;
	size_t	k;
	double	sum;

	i = 0;
	j = 0;
	k = 0;
	sum = 0.0;
	while (i < m.rows)
	{
		k = i;
		while (k < m.rows)
		{
			j = 0;
			while (j < i)
			{
				sum += m.data[i][j] * m.data[j][k];
				j++;
			}
			lu->data[i][k] = m.data[i][k] - sum;
			k++;
		}
		i++;
	}
	k = i + 1;
	while (k < m.rows)
	{
		sum = 0.0;
		j = 0;
		while (j < i)
		{
			sum += m.data[k][j] * m.data[j][i];
			j++;
		}
		lu->data[k][i] = (m.data[k][i] - sum) / m.data[i][i];
		k++;
	}
}
