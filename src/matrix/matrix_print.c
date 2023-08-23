/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 21:11:43 by arobu             #+#    #+#             */
/*   Updated: 2023/08/01 21:11:43 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <math.h>

inline void	matrix_print(t_matrix m)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < m.rows)
	{
		j = 0;
		while (j < m.cols)
		{
			if (fabs(m.data[i][j]) < M_EPSILON)
				printf("0.000000 ");
			else
				printf("%.6f ", m.data[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
