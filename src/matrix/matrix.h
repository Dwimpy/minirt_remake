/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 00:58:42 by arobu             #+#    #+#             */
/*   Updated: 2023/07/31 00:58:42 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H
# define ERR_MTX_ALLOC_FAILED "Matrix allocation failed. Exiting."
# define ERR_MTX_OUT_OF_RANGE "Matrix index out of range. Exiting."
# define ERR_MTX_SAME_DIMENSION "Matrices do not have the same dimension. Exiting."

#include "stdlib.h"
#include "unistd.h"
#include "libft.h"
#include "stdbool.h"

typedef struct s_matrix
{
	int			dimension;
	double		*matrix;
}				t_matrix;

t_matrix	matrix_init(int dimension);
t_matrix	matrix_multiply(t_matrix a, t_matrix b);
void		matrix_set_element_at(t_matrix mtx, int row, int column, double value);
double		matrix_get_element_at(t_matrix mtx, int row, int column);
bool		matrix_equal(t_matrix m1, t_matrix m2);

#endif