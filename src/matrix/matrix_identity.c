/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_identity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 21:49:00 by arobu             #+#    #+#             */
/*   Updated: 2023/08/14 15:10:35 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

inline void	matrix_identity(t_matrix *m)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < m->rows)
	{
		j = 0;
		while (j < m->cols)
		{
			if (i == j)
				m->data[i][j] = 1.0;
			else
				m->data[i][j] = 0.0;
			j++;
		}
		i++;
	}
}
