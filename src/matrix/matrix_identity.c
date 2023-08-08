/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_identity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 21:49:00 by arobu             #+#    #+#             */
/*   Updated: 2023/08/08 03:35:41 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "matrix.h"

inline t_matrix matrix_identity(void) {
	t_matrix	matrix;
	size_t		i;

	i = 0;
	matrix = matrix_init(4, 4);
	while (i < matrix.rows)
	{
		matrix.data[i][i] = 1.0;
		i++;
	}
	return (matrix);
}
