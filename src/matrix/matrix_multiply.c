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


inline t_matrix matrix_multiply(t_matrix m1, t_matrix m2)
{
	t_matrix	result;

	result = matrix_init(m1.rows, m2.cols);
	result.data[0][0] = m1.data[0][0]*m2.data[0][0] + m1.data[0][1]*m2.data[1][0] + m1.data[0][2]*m2.data[2][0] + m1.data[0][3]*m2.data[3][0];
	result.data[0][1] = m1.data[0][0]*m2.data[0][1] + m1.data[0][1]*m2.data[1][1] + m1.data[0][2]*m2.data[2][1] + m1.data[0][3]*m2.data[3][1];
	result.data[0][2] = m1.data[0][0]*m2.data[0][2] + m1.data[0][1]*m2.data[1][2] + m1.data[0][2]*m2.data[2][2] + m1.data[0][3]*m2.data[3][2];
	result.data[0][3] = m1.data[0][0]*m2.data[0][3] + m1.data[0][1]*m2.data[1][3] + m1.data[0][2]*m2.data[2][3] + m1.data[0][3]*m2.data[3][3];
	result.data[1][0] = m1.data[1][0]*m2.data[0][0] + m1.data[1][1]*m2.data[1][0] + m1.data[1][2]*m2.data[2][0] + m1.data[1][3]*m2.data[3][0];
	result.data[1][1] = m1.data[1][0]*m2.data[0][1] + m1.data[1][1]*m2.data[1][1] + m1.data[1][2]*m2.data[2][1] + m1.data[1][3]*m2.data[3][1];
	result.data[1][2] = m1.data[1][0]*m2.data[0][2] + m1.data[1][1]*m2.data[1][2] + m1.data[1][2]*m2.data[2][2] + m1.data[1][3]*m2.data[3][2];
	result.data[1][3] = m1.data[1][0]*m2.data[0][3] + m1.data[1][1]*m2.data[1][3] + m1.data[1][2]*m2.data[2][3] + m1.data[1][3]*m2.data[3][3];
	result.data[2][0] = m1.data[2][0]*m2.data[0][0] + m1.data[2][1]*m2.data[1][0] + m1.data[2][2]*m2.data[2][0] + m1.data[2][3]*m2.data[3][0];
	result.data[2][1] = m1.data[2][0]*m2.data[0][1] + m1.data[2][1]*m2.data[1][1] + m1.data[2][2]*m2.data[2][1] + m1.data[2][3]*m2.data[3][1];
	result.data[2][2] = m1.data[2][0]*m2.data[0][2] + m1.data[2][1]*m2.data[1][2] + m1.data[2][2]*m2.data[2][2] + m1.data[2][3]*m2.data[3][2];
	result.data[2][3] = m1.data[2][0]*m2.data[0][3] + m1.data[2][1]*m2.data[1][3] + m1.data[2][2]*m2.data[2][3] + m1.data[2][3]*m2.data[3][3];
	result.data[3][0] = m1.data[3][0]*m2.data[0][0] + m1.data[3][1]*m2.data[1][0] + m1.data[3][2]*m2.data[2][0] + m1.data[3][3]*m2.data[3][0];
	result.data[3][1] = m1.data[3][0]*m2.data[0][1] + m1.data[3][1]*m2.data[1][1] + m1.data[3][2]*m2.data[2][1] + m1.data[3][3]*m2.data[3][1];
	result.data[3][2] = m1.data[3][0]*m2.data[0][2] + m1.data[3][1]*m2.data[1][2] + m1.data[3][2]*m2.data[2][2] + m1.data[3][3]*m2.data[3][2];
	result.data[3][3] = m1.data[3][0]*m2.data[0][3] + m1.data[3][1]*m2.data[1][3] + m1.data[3][2]*m2.data[2][3] + m1.data[3][3]*m2.data[3][3];
	return (result);
}
