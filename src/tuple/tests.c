/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:06:15 by arobu             #+#    #+#             */
/*   Updated: 2023/07/30 19:06:15 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"
#include "assert.h"

void	tuple_tests(void)
{
	t_tuple	a;
	t_tuple norm;
	t_tuple	cross;
	double	mag;
	double	dot;

	a = tuple_new_point(4.3, -4.2, 3.1);
	assert(a.w == 1);

	a = tuple_new_vector(4.3, -4.2, 3.1);
	assert(a.w == 0);

	a = tuple_subtract(tuple_new_point(3, 2 , 1), tuple_new_point(5, 6, 7));
	assert(a.w == 0);
	assert(a.x == -2);
	assert(a.y == -4);
	assert(a.z == -6);

	a = tuple_subtract(tuple_new_point(3, 2 , 1), tuple_new_vector(5, 6, 7));
	assert(a.w == 1);
	assert(a.x == -2);
	assert(a.y == -4);
	assert(a.z == -6);

		a = tuple_subtract(tuple_new_vector(3, 2 , 1), tuple_new_vector(5, 6, 7));
	assert(a.w == 0);
	assert(a.x == -2);
	assert(a.y == -4);
	assert(a.z == -6);

	a = tuple_subtract(tuple_vector_zero(), tuple_new_vector(1, -2, 3));
	assert(a.w == 0);
	assert(a.x == -1);
	assert(a.y == 2);
	assert(a.z == -3);

	a = tuple_negate(tuple_new_point(1, -2, 3));
	assert(a.w == -1);
	assert(a.x == -1);
	assert(a.y == 2);
	assert(a.z == -3);

	a = tuple_multiply_s(tuple_new_point(1, -2, 3), 3.5);
	assert(a.w == 3.5);
	assert(a.x == 3.5);
	assert(a.y == -7);
	assert(a.z == 10.5);

	a = tuple_multiply_s(tuple_new_point(1, -2, 3), 0.5);
	assert(a.w == 0.5);
	assert(a.x == 0.5);
	assert(a.y == -1);
	assert(a.z == 1.5);

	a = tuple_division_s(tuple_new_point(1, -2, 3), 2);
	assert(a.w == 0.5);
	assert(a.x == 0.5);
	assert(a.y == -1);
	assert(a.z == 1.5);

	mag = tuple_magnitude(tuple_new_vector(0, 1, 0));
	assert(mag == 1);

	mag = tuple_magnitude(tuple_new_vector(0, 0, 1));
	assert(mag == 1);

	mag = tuple_magnitude(tuple_new_vector(1, 2, 3));
	assert(mag == sqrt(14));

	mag = tuple_magnitude(tuple_new_vector(-1, -2, -3));
	assert(mag == sqrt(14));

	norm = tuple_normalize(tuple_new_vector(4, 0, 0));
	assert(norm.x == 1);
	assert(norm.y == 0);
	assert(norm.z == 0);

	norm = tuple_normalize(tuple_new_vector(1, 2, 3));
	assert(is_approx_equal(norm.x, 0.26726, M_EPSILON));
	assert(is_approx_equal(norm.y, 0.53452, M_EPSILON));
	assert(is_approx_equal(norm.z, 0.80178, M_EPSILON));

	mag = tuple_magnitude(norm);
	assert(mag == 1);

	dot = tuple_dot(tuple_new_vector(1, 2, 3), tuple_new_vector(2, 3, 4));
	assert(dot == 20);

	cross = tuple_cross(tuple_new_vector(1, 2, 3), tuple_new_vector(2, 3, 4));
	assert(cross.x == -1);
	assert(cross.y == 2);
	assert(cross.z == -1);

	cross = tuple_cross(tuple_new_vector(2, 3, 4), tuple_new_vector(1, 2, 3));
	assert(cross.x == 1);
	assert(cross.y == -2);
	assert(cross.z == 1);

	a = tuple_reflect(tuple_new_vector(1, -1, 0), tuple_new_vector(0, 1, 0));
	assert(is_approx_equal(a.x, 1, M_EPSILON));
	assert(is_approx_equal(a.y, 1, M_EPSILON));
	assert(is_approx_equal(a.z, 0, M_EPSILON));

	a = tuple_reflect(tuple_new_vector(0, -1, 0), tuple_new_vector(sqrt(2) / 2, sqrt(2) / 2, 0));
	assert(is_approx_equal(a.x, 1, M_EPSILON));
	assert(is_approx_equal(a.y, 0, M_EPSILON));
	assert(is_approx_equal(a.z, 0, M_EPSILON));
}