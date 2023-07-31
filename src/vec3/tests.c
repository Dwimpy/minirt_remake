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

#include "vec3.h"

void	vec3_test(void)
{
	t_vec3 v = {1.0, 5.0, 10.0};
	t_vec3 v1 = {1.0, 2.0, 3.0};
	t_vec3 v2 = {4.0, 5.0, 6.0};
	double min = 2.0;
	double max = 8.0;


	// Test vec3_zero()
	// Test vec3_zero()
	t_vec3 zero = vec3_zero();
	if (!vec3_equal_s(zero, 0.0)) {
		printf("\033[1;91mTest failed\033[0;39m: vec3_zero()\n");
		printf("Got: ");
		vec3_print(zero);
		printf("Expected: (0.000000, 0.000000, 0.000000)\n");
	} else {
		printf("\033[1;92mTest passed\033[0;39m: vec3_zero()\n");
	}

	// Test vec3_add()
	t_vec3 sum = vec3_add(v1, v2);
	if (!vec3_equal(sum, (t_vec3){5.0, 7.0, 9.0})) {
		printf("\033[1;91mTest failed\033[0;39m: vec3_add()\n");
		printf("Got: ");
		vec3_print(sum);
		printf("Expected: (5.000000, 7.000000, 9.000000)\n");
	} else {
		printf("\033[1;92mTest passed\033[0;39m: vec3_add()\n");
	}

	// Test vec3_subtract()
	t_vec3 diff = vec3_subtract(v1, v2);
	if (!vec3_equal(diff, (t_vec3){-3.0, -3.0, -3.0})) {
		printf("\033[1;91mTest failed\033[0;39m: vec3_subtract()\n");
		printf("Got: ");
		vec3_print(diff);
		printf("Expected: (-3.000000, -3.000000, -3.000000)\n");
	} else {
		printf("\033[1;92mTest passed\033[0;39m: vec3_subtract()\n");
	}

	// Test vec3_multiply_s()
	t_real scalar = 2.0;
	t_vec3 scaled = vec3_multiply_s(v1, scalar);
	if (!vec3_equal(scaled, (t_vec3){2.0, 4.0, 6.0})) {
		printf("\033[1;91mTest failed\033[0;39m: vec3_multiply_s()\n");
		printf("Got: ");
		vec3_print(scaled);
		printf("Expected: (2.000000, 4.000000, 6.000000)\n");
	} else {
		printf("\033[1;92mTest passed\033[0;39m: vec3_multiply_s()\n");
	}

	// Test vec3_division_s()
	t_real divisor = 3.0;
	t_vec3 divided = vec3_division_s(v1, divisor);
	if (!vec3_equal(divided, (t_vec3){0.333333, 0.666667, 1.000000})) {
		printf("\033[1;91mTest failed\033[0;39m: vec3_division_s()\n");
		printf("Got: ");
		vec3_print(divided);
		printf("Expected: (0.333333, 0.666667, 1.000000)\n");
	} else {
		printf("\033[1;92mTest passed\033[0;39m: vec3_division_s()\n");
	}

	// Test vec3_division()
	t_vec3 v3 = {2.0, 4.0, 8.0};
	t_vec3 result = vec3_division(v3, v1);
	if (!vec3_equal(result, (t_vec3){2.0, 2.0, 2.666667})) {
		printf("\033[1;91mTest failed\033[0;39m: vec3_division()\n");
		printf("Got: ");
		vec3_print(result);
		printf("Expected: (2.000000, 2.000000, 2.666667)\n");
	} else {
		printf("\033[1;92mTest passed\033[0;39m: vec3_division()\n");
	}

	// Test vec3_negate()
	t_vec3 neg_v1 = vec3_negate(v1);
	if (!vec3_equal(neg_v1, (t_vec3){-1.0, -2.0, -3.0})) {
		printf("\033[1;91mTest failed\033[0;39m: vec3_negate()\n");
		printf("Got: ");
		vec3_print(neg_v1);
		printf("Expected: (-1.000000, -2.000000, -3.000000)\n");
	} else {
		printf("\033[1;92mTest passed\033[0;39m: vec3_negate()\n");
	}

	// Test vec3_dot()
	t_real dot_product = vec3_dot(v1, v2);
	if (dot_product != 32.0) {
		printf("\033[1;91mTest failed\033[0;39m: vec3_dot()\n");
		printf("Got: %lf\n", dot_product);
		printf("Expected: 32.000000\n");
	} else {
		printf("\033[1;92mTest passed\033[0;39m: vec3_dot()\n");
	}

	// Test vec3_magnitude()
	t_real magnitude_v1 = vec3_magnitude(v1);
	if (!is_approx_equal(magnitude_v1, 3.74165738, M_EPSILON)) {
		printf("\033[1;91mTest failed\033[0;39m: vec3_magnitude()\n");
		printf("Got: %lf\n", magnitude_v1);
		printf("Expected: 3.741657\n");
	} else {
		printf("\033[1;92mTest passed\033[0;39m: vec3_magnitude()\n");
	}

	// Test clamp()
	t_real res = clamp(3.5, min, max);
	if (!is_approx_equal(res, 3.5, M_EPSILON)) {
		printf("\033[1;91mTest failed\033[0;39m: clamp()\n");
		printf("Got: %lf\n", res);
		printf("Expected: 3.5\n");
	} else {
		printf("\033[1;92mTest passed\033[0;39m: clamp()\n");
	}

	// Test vec3_clamp()
	t_vec3 clamped = vec3_clamp(v, min, max);
	if (!is_approx_equal(clamped.x, 2.0, M_EPSILON) ||
		!is_approx_equal(clamped.y, 5.0, M_EPSILON) ||
		!is_approx_equal(clamped.z, 8.0, M_EPSILON)) {
		printf("\033[1;91mTest failed\033[0;39m: vec3_clamp()\n");
		printf("Got: (%lf, %lf, %lf)\n", clamped.x, clamped.y, clamped.z);
		printf("Expected: (2.0, 5.0, 8.0)\n");
	} else {
		printf("\033[1;92mTest passed\033[0;39m: vec3_clamp()\n");
	}

	t_vec3 cross_product = vec3_cross(v1, v2);
	t_vec3 expected_result = { -3.0, 6.0, -3.0 }; // The expected result of the cross product
	if (!vec3_equal(cross_product, expected_result))
	{
		printf("\033[1;91mTest failed\033[0;39m: vec3_cross()\n");
		printf("Got: (%lf, %lf, %lf)\n", cross_product.x, cross_product.y, cross_product.z);
		printf("Expected: (%lf, %lf, %lf)\n", expected_result.x, expected_result.y, expected_result.z);
	} else {
		printf("\033[1;92mTest passed\033[0;39m: vec3_cross()\n");
	}

}