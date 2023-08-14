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

inline void	matrix_transpose(t_matrix *transpose, t_matrix *m)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < m->rows)
	{
		j = 0;
		while (j < m->cols)
		{
			transpose->data[j][i] = m->data[i][j];
			j++;
		}
		i++;
	}
}