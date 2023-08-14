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
#include <stdlib.h>

void		matrix_set_aug_elements(t_matrix *mat, t_matrix m);
void		interchange_rows(t_matrix *m);
void		replace_row(t_matrix *m);
void		finalize_inverse(t_matrix *m);

void	matrix_inverse(t_matrix *inverse, t_matrix *m)
{
	t_matrix	aug_mtx;
	size_t		i;
	size_t		j;

	aug_mtx = matrix_init(m->rows, m->cols * 2);
	matrix_set_aug_elements(&aug_mtx, *m);
	interchange_rows(&aug_mtx);
	replace_row(&aug_mtx);
	finalize_inverse(&aug_mtx);
	i = 0;
	while (i < m->rows)
	{
		j = 0;
		while (j < m->rows)
		{
			inverse->data[i][j] = aug_mtx.data[i][j + m->rows];
			++j;
		}
		++i;
	}
	matrix_free(aug_mtx);
}

void	matrix_set_aug_elements(t_matrix *mat,t_matrix m)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < mat->rows)
	{
		j = 0;
		while (j < mat->cols)
		{
			if (j < m.rows)
				mat->data[i][j] = m.data[i][j];
			else if (j >= m.rows && j == i + m.rows)
				mat->data[i][j] = 1;
			++j;
		}
		++i;
	}
}

void	interchange_rows(t_matrix *m)
{
	size_t	i;
	t_real	*tmp_arr;

	i = m->rows - 1;
	while (i > 0)
	{
		if (m->data[i - 1][0] < m->data[i][0])
		{
			tmp_arr = m->data[i];
			m->data[i] = m->data[i - 1];
			m->data[i - 1] = tmp_arr;
		}
		--i;
	}
}

void	replace_row(t_matrix *m)
{
	size_t		i;
	size_t		j;
	size_t		k;
	t_real		temp;

	i = -1;
	while (++i < m->rows)
	{
		j = -1;
		while (++j < m->rows)
		{
			k = -1;
			if (j != i)
			{
				if (m->data[i][i] == 0)
					m->data[i][i] = M_EPSILON;
				temp = m->data[j][i] / (m->data[i][i]);
				while (++k < 2 * m->rows)
				{
					m->data[j][k] -= m->data[i][k] * temp;
				}
			}
		}
	}
}

void	finalize_inverse(t_matrix *m)
{
	size_t	i;
	size_t	j;
	double	tmp;

	i = 0;
	tmp = 0;
	while (i < m->rows)
	{
		tmp = m->data[i][i];
		j = 0;
		while (j < 2 * m->rows)
		{
			m->data[i][j] = m->data[i][j] / tmp;
			++j;
		}
		++i;
	}
}
