/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:18:31 by arobu             #+#    #+#             */
/*   Updated: 2023/08/09 15:18:31 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "tuple.h"

void matrix_tests()
{
	t_matrix a;
	t_matrix b;
	t_matrix ident;
	t_matrix result;
	t_tuple t_res;

	a = matrix_init(4, 4);
	matrix_set(a, 0, 0, 1);
	matrix_set(a, 0, 1, 2);
	matrix_set(a, 0, 2, 3);
	matrix_set(a, 0, 3, 4);

	matrix_set(a, 1, 0, 5);
	matrix_set(a, 1, 1, 6);
	matrix_set(a, 1, 2, 7);
	matrix_set(a, 1, 3, 8);

	matrix_set(a, 2, 0, 9);
	matrix_set(a, 2, 1, 8);
	matrix_set(a, 2, 2, 7);
	matrix_set(a, 2, 3, 6);

	matrix_set(a, 3, 0, 5);
	matrix_set(a, 3, 1, 4);
	matrix_set(a, 3, 2, 3);
	matrix_set(a, 3, 3, 2);

	b = matrix_init(4, 4);
	matrix_set(b, 0, 0, 1);
	matrix_set(b, 0, 1, 2);
	matrix_set(b, 0, 2, 3);
	matrix_set(b, 0, 3, 4);

	matrix_set(b, 1, 0, 5);
	matrix_set(b, 1, 1, 6);
	matrix_set(b, 1, 2, 7);
	matrix_set(b, 1, 3, 8);

	matrix_set(b, 2, 0, 9);
	matrix_set(b, 2, 1, 8);
	matrix_set(b, 2, 2, 7);
	matrix_set(b, 2, 3, 6);

	matrix_set(b, 3, 0, 5);
	matrix_set(b, 3, 1, 4);
	matrix_set(b, 3, 2, 3);
	matrix_set(b, 3, 3, 2);

	assert(matrix_equal(a, b));
	matrix_set(b, 3, 0, 4);
	matrix_set(b, 3, 1, 3);
	matrix_set(b, 3, 2, 2);
	matrix_set(b, 3, 3, 1);
	assert(!matrix_equal(a, b));

	matrix_set(b, 0, 0, -2);
	matrix_set(b, 0, 1, 1);
	matrix_set(b, 0, 2, 2);
	matrix_set(b, 0, 3, 3);

	matrix_set(b, 1, 0, 3);
	matrix_set(b, 1, 1, 2);
	matrix_set(b, 1, 2, 1);
	matrix_set(b, 1, 3, -1);

	matrix_set(b, 2, 0, 4);
	matrix_set(b, 2, 1, 3);
	matrix_set(b, 2, 2, 6);
	matrix_set(b, 2, 3, 5);

	matrix_set(b, 3, 0, 1);
	matrix_set(b, 3, 1, 2);
	matrix_set(b, 3, 2, 7);
	matrix_set(b, 3, 3, 8);

	result = matrix_multiply(a, b);
	assert(result.data[0][0] == 20);
	assert(result.data[0][1] == 22);
	assert(result.data[0][2] == 50);
	assert(result.data[0][3] == 48);

	assert(result.data[1][0] == 44);
	assert(result.data[1][1] == 54);
	assert(result.data[1][2] == 114);
	assert(result.data[1][3] == 108);

	assert(result.data[2][0] == 40);
	assert(result.data[2][1] == 58);
	assert(result.data[2][2] == 110);
	assert(result.data[2][3] == 102);

	assert(result.data[3][0] == 16);
	assert(result.data[3][1] == 26);
	assert(result.data[3][2] == 46);
	assert(result.data[3][3] == 42);

	matrix_set(a, 0, 0, 1);
	matrix_set(a, 0, 1, 2);
	matrix_set(a, 0, 2, 3);
	matrix_set(a, 0, 3, 4);

	matrix_set(a, 1, 0, 2);
	matrix_set(a, 1, 1, 4);
	matrix_set(a, 1, 2, 4);
	matrix_set(a, 1, 3, 2);

	matrix_set(a, 2, 0, 8);
	matrix_set(a, 2, 1, 6);
	matrix_set(a, 2, 2, 4);
	matrix_set(a, 2, 3, 1);

	matrix_set(a, 3, 0, 0);
	matrix_set(a, 3, 1, 0);
	matrix_set(a, 3, 2, 0);
	matrix_set(a, 3, 3, 1);
	t_res = matrix_multiply_tuple(a, tuple_new_point(1, 2, 3));
	assert(t_res.x == 18);
	assert(t_res.y == 24);
	assert(t_res.z == 33);
	assert(t_res.w == 1);

	ident = matrix_identity();
	t_res = matrix_multiply_tuple(ident, tuple_new_point(1, 2, 3));
	assert(t_res.x == 1);
	assert(t_res.y == 2);
	assert(t_res.z == 3);
	assert(t_res.w == 1);

	result = matrix_transpose(a);
	assert(result.data[0][0] == 1);
	assert(result.data[0][1] == 2);
	assert(result.data[0][2] == 8);
	assert(result.data[0][3] == 0);

	assert(result.data[1][0] == 2);
	assert(result.data[1][1] == 4);
	assert(result.data[1][2] == 6);
	assert(result.data[1][3] == 0);

	assert(result.data[2][0] == 3);
	assert(result.data[2][1] == 4);
	assert(result.data[2][2] == 4);
	assert(result.data[2][3] == 0);

	assert(result.data[3][0] == 4);
	assert(result.data[3][1] == 2);
	assert(result.data[3][2] == 1);
	assert(result.data[3][3] == 1);

	matrix_set(a, 0, 0, 8);
	matrix_set(a, 0, 1, -5);
	matrix_set(a, 0, 2, 9);
	matrix_set(a, 0, 3, 2);

	matrix_set(a, 1, 0, 7);
	matrix_set(a, 1, 1, 5);
	matrix_set(a, 1, 2, 6);
	matrix_set(a, 1, 3, 1);

	matrix_set(a, 2, 0, -6);
	matrix_set(a, 2, 1, 0);
	matrix_set(a, 2, 2, 9);
	matrix_set(a, 2, 3, 6);

	matrix_set(a, 3, 0, -3);
	matrix_set(a, 3, 1, 0);
	matrix_set(a, 3, 2, -9);
	matrix_set(a, 3, 3, -4);

	result = matrix_inverse(a);

	assert(is_approx_equal(result.data[0][0], -0.15385, M_EPSILON));
	assert(is_approx_equal(result.data[0][1], -0.15385, M_EPSILON));
	assert(is_approx_equal(result.data[0][2], -0.28205, M_EPSILON));
	assert(is_approx_equal(result.data[0][3], -0.53846, M_EPSILON));

	assert(is_approx_equal(result.data[1][0], -0.07692, M_EPSILON));
	assert(is_approx_equal(result.data[1][1], 0.12308, M_EPSILON));
	assert(is_approx_equal(result.data[1][2], 0.02564, M_EPSILON));
	assert(is_approx_equal(result.data[1][3], 0.03077, M_EPSILON));

	assert(is_approx_equal(result.data[2][0], 0.35897, M_EPSILON));
	assert(is_approx_equal(result.data[2][1], 0.35897, M_EPSILON));
	assert(is_approx_equal(result.data[2][2], 0.43590, M_EPSILON));
	assert(is_approx_equal(result.data[2][3], 0.92308, M_EPSILON));

	assert(is_approx_equal(result.data[3][0], -0.69231, M_EPSILON));
	assert(is_approx_equal(result.data[3][1], -0.69231, M_EPSILON));
	assert(is_approx_equal(result.data[3][2], -0.76923, M_EPSILON));
	assert(is_approx_equal(result.data[3][3], -1.92308, M_EPSILON));

	matrix_set(a, 0, 0, -5);
	matrix_set(a, 0, 1, 2);
	matrix_set(a, 0, 2, 6);
	matrix_set(a, 0, 3, -8);

	matrix_set(a, 1, 0, 1);
	matrix_set(a, 1, 1, -5);
	matrix_set(a, 1, 2, 1);
	matrix_set(a, 1, 3, 8);

	matrix_set(a, 2, 0, 7);
	matrix_set(a, 2, 1, 7);
	matrix_set(a, 2, 2, -6);
	matrix_set(a, 2, 3, -7);

	matrix_set(a, 3, 0, 1);
	matrix_set(a, 3, 1, -3);
	matrix_set(a, 3, 2, 7);
	matrix_set(a, 3, 3, 4);

	result = matrix_inverse(a);

	assert(is_approx_equal(result.data[0][0], 0.21805, M_EPSILON));
	assert(is_approx_equal(result.data[0][1], 0.45113, M_EPSILON));
	assert(is_approx_equal(result.data[0][2], 0.24060, M_EPSILON));
	assert(is_approx_equal(result.data[0][3], -0.04511, M_EPSILON));

	assert(is_approx_equal(result.data[1][0], -0.80827, M_EPSILON));
	assert(is_approx_equal(result.data[1][1], -1.45677, M_EPSILON));
	assert(is_approx_equal(result.data[1][2], -0.44361 , M_EPSILON));
	assert(is_approx_equal(result.data[1][3], 0.52068, M_EPSILON));

	assert(is_approx_equal(result.data[2][0], -0.07895, M_EPSILON));
	assert(is_approx_equal(result.data[2][1], -0.22368, M_EPSILON));
	assert(is_approx_equal(result.data[2][2], -0.05263, M_EPSILON));
	assert(is_approx_equal(result.data[2][3], 0.19737, M_EPSILON));

	assert(is_approx_equal(result.data[3][0], -0.52256, M_EPSILON));
	assert(is_approx_equal(result.data[3][1], -0.81391, M_EPSILON));
	assert(is_approx_equal(result.data[3][2], -0.30075, M_EPSILON));
	assert(is_approx_equal(result.data[3][3], 0.30639, M_EPSILON));

	matrix_set(a, 0, 0, 3);
	matrix_set(a, 0, 1, -9);
	matrix_set(a, 0, 2, 7);
	matrix_set(a, 0, 3, 3);

	matrix_set(a, 1, 0, 3);
	matrix_set(a, 1, 1, -8);
	matrix_set(a, 1, 2, 2);
	matrix_set(a, 1, 3, -9);

	matrix_set(a, 2, 0, -4);
	matrix_set(a, 2, 1, 4);
	matrix_set(a, 2, 2, 4);
	matrix_set(a, 2, 3, -1);

	matrix_set(a, 3, 0, -6);
	matrix_set(a, 3, 1, 5);
	matrix_set(a, 3, 2, -1);
	matrix_set(a, 3, 3, 1);

	matrix_set(b, 0, 0, 8);
	matrix_set(b, 0, 1, 2);
	matrix_set(b, 0, 2, 2);
	matrix_set(b, 0, 3, 2);

	matrix_set(b, 1, 0, 3);
	matrix_set(b, 1, 1, -1);
	matrix_set(b, 1, 2, 7);
	matrix_set(b, 1, 3, 0);

	matrix_set(b, 2, 0, 7);
	matrix_set(b, 2, 1, 0);
	matrix_set(b, 2, 2, 5);
	matrix_set(b, 2, 3, 4);

	matrix_set(b, 3, 0, 6);
	matrix_set(b, 3, 1, -2);
	matrix_set(b, 3, 2, 0);
	matrix_set(b, 3, 3, 5);
	result = matrix_multiply(a, b);
	assert(matrix_equal(matrix_multiply(result, matrix_inverse(b)),a));
}
