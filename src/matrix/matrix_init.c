/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 01:03:09 by arobu             #+#    #+#             */
/*   Updated: 2023/07/31 01:03:09 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "matrix.h"

t_matrix matrix_init(int dimension) {
	t_matrix mtx;

	mtx.matrix = (double *) malloc(sizeof(double) * dimension * dimension);
	mtx.dimension = dimension;
	if (!mtx.matrix) {
		write(2, ERR_MTX_ALLOC_FAILED, 35);
		exit(EXIT_FAILURE);
	}
	ft_bzero(mtx.matrix, sizeof(double) * dimension * dimension);
	return (mtx);
}