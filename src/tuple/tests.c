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
	t_tuple v = {1.0, 5.0, 10.0};
	t_tuple v1 = {1.0, 2.0, 3.0};
	t_tuple v2 = {4.0, 5.0, 6.0};
	double min = 2.0;
	double max = 8.0;


	// Test tuple_vector_zero()
	t_tuple zero = tuple_vector_zero();
	assert(tuple_equal_s(zero, 0.0));
	printf("\033[1;92mTest passed\033[0;39m: tuple_vector_zero()\n");

	// Test tuple_add()
	t_tuple sum = tuple_add(v1, v2);
	assert(tuple_equal(sum, (t_tuple) {5.0, 7.0, 9.0}));
	printf("\033[1;92mTest passed\033[0;39m: tuple_add()\n");

	// Test tuple_subtract()
	t_tuple diff = tuple_subtract(v1, v2);
	assert(tuple_equal(diff, (t_tuple) {-3.0, -3.0, -3.0}));
	printf("\033[1;92mTest passed\033[0;39m: tuple_subtract()\n");

	// Test tuple_multiply_s()
	t_real scalar = 2.0;
	t_tuple scaled = tuple_multiply_s(v1, scalar);
	assert(tuple_equal(scaled, (t_tuple) {2.0, 4.0, 6.0}));
	printf("\033[1;92mTest passed\033[0;39m: tuple_multiply_s()\n");

	// Test tuple_division_s()
	t_real divisor = 3.0;
	t_tuple divided = tuple_division_s(v1, divisor);
	assert(tuple_equal(divided, (t_tuple) {0.333333, 0.666667, 1.000000}));
	printf("\033[1;92mTest passed\033[0;39m: tuple_division_s()\n");

	// Test tuple_division()
	t_tuple v3 = {2.0, 4.0, 8.0};
	t_tuple result = tuple_division(v3, v1);
	assert(tuple_equal(result, (t_tuple) {2.0, 2.0, 2.666667}));
	printf("\033[1;92mTest passed\033[0;39m: tuple_division()\n");

	// Test tuple_negate()
	t_tuple neg_v1 = tuple_negate(v1);
	assert(tuple_equal(neg_v1, (t_tuple) {-1.0, -2.0, -3.0}));
	printf("\033[1;92mTest passed\033[0;39m: tuple_negate()\n");

	// Test tuple_dot()
	t_real dot_product = tuple_dot(v1, v2);
	assert(dot_product == 32.0);
	printf("\033[1;92mTest passed\033[0;39m: tuple_dot()\n");

	// Test tuple_magnitude()
	t_real magnitude_v1 = tuple_magnitude(v1);
	assert(is_approx_equal(magnitude_v1, 3.74165738, M_EPSILON));
	printf("\033[1;92mTest passed\033[0;39m: tuple_magnitude()\n");

	// Test clamp()
	t_real res = clamp(3.5, min, max);
	assert(is_approx_equal(res, 3.5, M_EPSILON));
	printf("\033[1;92mTest passed\033[0;39m: clamp()\n");

	// Test tuple_clamp()
	t_tuple clamped = tuple_clamp(v, min, max);
	assert(is_approx_equal(clamped.x, 2.0, M_EPSILON));
	assert(is_approx_equal(clamped.y, 5.0, M_EPSILON));
	assert(is_approx_equal(clamped.z, 8.0, M_EPSILON));
	printf("\033[1;92mTest passed\033[0;39m: tuple_clamp()\n");

	// Test tuple_cross()
	t_tuple cross_product = tuple_cross(v1, v2);
	t_tuple expected_result = {-3.0, 6.0, -3.0};
	assert(tuple_equal(cross_product, expected_result));
	printf("\033[1;92mTest passed\033[0;39m: tuple_cross()\n");

}