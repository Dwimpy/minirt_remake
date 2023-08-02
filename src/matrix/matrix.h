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


# define ERR_MTX_ALLOC_FAILED "Matrix allocation failed. Exiting.\n"
# define ERR_MTX_OUT_OF_RANGE "Matrix index out of range. Exiting.\n"
# define ERR_MTX_SAME_DIMENSION "Matrices do not have the same dimension. Exiting.\n"

#include "tuple.h"
#include <stdint.h>
#include "stdlib.h"
#include "unistd.h"
#include "libft.h"
#include "stdbool.h"
#include "stdio.h"


typedef struct s_matrix
{
	size_t		rows;
	size_t		cols;
	double		**data;
}				t_matrix;

t_matrix	matrix_init(size_t rows, size_t cols);
t_matrix	matrix_identity(void);
t_matrix	matrix_multiply(t_matrix a, t_matrix b);
t_matrix	matrix_transpose(t_matrix m);
t_matrix	matrix_inverse(t_matrix mat);
t_tuple		matrix_multiply_tuple(t_matrix m, t_tuple t);
void		matrix_set(t_matrix mtx, size_t row, size_t column, double value);
double		matrix_get(t_matrix mtx, size_t row, size_t column);
bool		matrix_equal(t_matrix m1, t_matrix m2);
void		matrix_print(t_matrix m);
void		matrix_free(t_matrix m);

#endif