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

inline static void	copy_matrix_elements(t_matrix *result, t_matrix *tmp);

inline void	matrix_multiply(t_matrix *result, t_matrix *m1, t_matrix *m2)
{
	t_matrix	tmp;

	tmp = matrix_init(4, 4);
	tmp.data[0][0] = m1->data[0][0]*m2->data[0][0] + m1->data[0][1]*m2->data[1][0] + m1->data[0][2]*m2->data[2][0] + m1->data[0][3]*m2->data[3][0];
	tmp.data[0][1] = m1->data[0][0]*m2->data[0][1] + m1->data[0][1]*m2->data[1][1] + m1->data[0][2]*m2->data[2][1] + m1->data[0][3]*m2->data[3][1];
	tmp.data[0][2] = m1->data[0][0]*m2->data[0][2] + m1->data[0][1]*m2->data[1][2] + m1->data[0][2]*m2->data[2][2] + m1->data[0][3]*m2->data[3][2];
	tmp.data[0][3] = m1->data[0][0]*m2->data[0][3] + m1->data[0][1]*m2->data[1][3] + m1->data[0][2]*m2->data[2][3] + m1->data[0][3]*m2->data[3][3];
	tmp.data[1][0] = m1->data[1][0]*m2->data[0][0] + m1->data[1][1]*m2->data[1][0] + m1->data[1][2]*m2->data[2][0] + m1->data[1][3]*m2->data[3][0];
	tmp.data[1][1] = m1->data[1][0]*m2->data[0][1] + m1->data[1][1]*m2->data[1][1] + m1->data[1][2]*m2->data[2][1] + m1->data[1][3]*m2->data[3][1];
	tmp.data[1][2] = m1->data[1][0]*m2->data[0][2] + m1->data[1][1]*m2->data[1][2] + m1->data[1][2]*m2->data[2][2] + m1->data[1][3]*m2->data[3][2];
	tmp.data[1][3] = m1->data[1][0]*m2->data[0][3] + m1->data[1][1]*m2->data[1][3] + m1->data[1][2]*m2->data[2][3] + m1->data[1][3]*m2->data[3][3];
	tmp.data[2][0] = m1->data[2][0]*m2->data[0][0] + m1->data[2][1]*m2->data[1][0] + m1->data[2][2]*m2->data[2][0] + m1->data[2][3]*m2->data[3][0];
	tmp.data[2][1] = m1->data[2][0]*m2->data[0][1] + m1->data[2][1]*m2->data[1][1] + m1->data[2][2]*m2->data[2][1] + m1->data[2][3]*m2->data[3][1];
	tmp.data[2][2] = m1->data[2][0]*m2->data[0][2] + m1->data[2][1]*m2->data[1][2] + m1->data[2][2]*m2->data[2][2] + m1->data[2][3]*m2->data[3][2];
	tmp.data[2][3] = m1->data[2][0]*m2->data[0][3] + m1->data[2][1]*m2->data[1][3] + m1->data[2][2]*m2->data[2][3] + m1->data[2][3]*m2->data[3][3];
	tmp.data[3][0] = m1->data[3][0]*m2->data[0][0] + m1->data[3][1]*m2->data[1][0] + m1->data[3][2]*m2->data[2][0] + m1->data[3][3]*m2->data[3][0];
	tmp.data[3][1] = m1->data[3][0]*m2->data[0][1] + m1->data[3][1]*m2->data[1][1] + m1->data[3][2]*m2->data[2][1] + m1->data[3][3]*m2->data[3][1];
	tmp.data[3][2] = m1->data[3][0]*m2->data[0][2] + m1->data[3][1]*m2->data[1][2] + m1->data[3][2]*m2->data[2][2] + m1->data[3][3]*m2->data[3][2];
	tmp.data[3][3] = m1->data[3][0]*m2->data[0][3] + m1->data[3][1]*m2->data[1][3] + m1->data[3][2]*m2->data[2][3] + m1->data[3][3]*m2->data[3][3];
	copy_matrix_elements(result, &tmp);
	matrix_free(tmp);
}

inline static void	copy_matrix_elements(t_matrix *result, t_matrix *tmp)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < tmp->rows)
	{
		j = -1;
		while (++j < tmp->cols)
		{
			result->data[i][j] = tmp->data[i][j];
		}
	}
}