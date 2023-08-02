/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transpose.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 22:39:41 by arobu             #+#    #+#             */
/*   Updated: 2023/08/01 22:39:41 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

inline t_matrix	matrix_transpose(t_matrix m)
{
	t_matrix	transpose;
	size_t		i;
	size_t		j;

	transpose = matrix_init(m.rows, m.cols);
	i = 0;
	while (i < m.rows)
	{
		j = 0;
		while (j < m.cols)
		{
			transpose.data[j][i] = m.data[i][j];
			j++;
		}
		i++;
	}
	return (transpose);
}