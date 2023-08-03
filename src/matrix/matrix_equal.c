/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_equal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:20:36 by arobu             #+#    #+#             */
/*   Updated: 2023/08/01 19:20:36 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

inline bool	matrix_equal(t_matrix m1, t_matrix m2)
{
	size_t	i;
	size_t	j;

	if (m1.rows != m2.rows && m1.cols != m2.cols)
		return (false);
	i = 0;
	while (i < m1.rows)
	{
		j = 0;
		while (j < m2.cols)
		{
			if (m1.data[i][j] != m2.data[i][j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}