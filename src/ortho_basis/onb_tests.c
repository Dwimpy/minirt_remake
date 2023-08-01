/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onb_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:32:04 by arobu             #+#    #+#             */
/*   Updated: 2023/07/31 19:32:04 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "onb.h"
#include "assert.h"

void	onb_tests()
{
	t_tuple u = {1.0, 0.0, 0.0};
	t_tuple v = {0.0, 1.0, 0.0};
	t_tuple w = {0.0, 0.0, 1.0};

	// Test onb_init_from_u()
	t_onb basis = onb_init_from_u(u);
	assert(tuple_equal(basis.u, (t_tuple) {1.0, 0.0, 0.0}));
	assert(is_approx_equal(tuple_dot(basis.u, basis.v), 0.0, 1e-6));
	assert(is_approx_equal(tuple_dot(basis.u, basis.w), 0.0, 1e-6));
	assert(is_approx_equal(tuple_dot(basis.v, basis.w), 0.0, 1e-6));
	printf("\033[1;92mTest passed\033[0;39m: onb_init_from_u()\n");

	// Test onb_init_from_v()
	basis = onb_init_from_v(v);
	assert(tuple_equal(basis.v, (t_tuple) {0.0, 1.0, 0.0}));
	assert(is_approx_equal(tuple_dot(basis.u, basis.v), 0.0, 1e-6));
	assert(is_approx_equal(tuple_dot(basis.v, basis.w), 0.0, 1e-6));
	assert(is_approx_equal(tuple_dot(basis.u, basis.w), 0.0, 1e-6));
	printf("\033[1;92mTest passed\033[0;39m: onb_init_from_v()\n");

	// Test onb_init_from_w()
	basis = onb_init_from_w(w);
	assert(tuple_equal(basis.w, (t_tuple) {0.0, 0.0, 1.0}));
	assert(is_approx_equal(tuple_dot(basis.u, basis.w), 0.0, 1e-6));
	assert(is_approx_equal(tuple_dot(basis.v, basis.w), 0.0, 1e-6));
	assert(is_approx_equal(tuple_dot(basis.u, basis.v), 0.0, 1e-6));
	printf("\033[1;92mTest passed\033[0;39m: onb_init_from_w()\n");

	// Test onb_init_from_uv()
	basis = onb_init_from_uv(u, v);
	assert(tuple_equal(basis.u, (t_tuple) {1.0, 0.0, 0.0}));
	assert(tuple_equal(basis.v, (t_tuple) {0.0, 1.0, 0.0}));
	assert(is_approx_equal(tuple_dot(basis.u, basis.v), 0.0, 1e-6));
	assert(is_approx_equal(tuple_dot(basis.u, basis.w), 0.0, 1e-6));
	assert(is_approx_equal(tuple_dot(basis.v, basis.w), 0.0, 1e-6));
	printf("\033[1;92mTest passed\033[0;39m: onb_init_from_uv()\n");

	// Test onb_init_from_vu()
	basis = onb_init_from_vu(v, u);
	assert(tuple_equal(basis.u, (t_tuple) {1.0, 0.0, 0.0}));
	assert(tuple_equal(basis.v, (t_tuple) {0.0, 1.0, 0.0}));
	assert(is_approx_equal(tuple_dot(basis.u, basis.v), 0.0, 1e-6));
	assert(is_approx_equal(tuple_dot(basis.u, basis.w), 0.0, 1e-6));
	assert(is_approx_equal(tuple_dot(basis.v, basis.w), 0.0, 1e-6));
	printf("\033[1;92mTest passed\033[0;39m: onb_init_from_vu()\n");

	// Test onb_init_from_uw()
	basis = onb_init_from_uw(u, w);
	assert(tuple_equal(basis.u, (t_tuple) {1.0, 0.0, 0.0}));
	assert(tuple_equal(basis.w, (t_tuple) {0.0, 0.0, 1.0}));
	assert(is_approx_equal(tuple_dot(basis.u, basis.v), 0.0, 1e-6));
	assert(is_approx_equal(tuple_dot(basis.u, basis.w), 0.0, 1e-6));
	assert(is_approx_equal(tuple_dot(basis.v, basis.w), 0.0, 1e-6));
	printf("\033[1;92mTest passed\033[0;39m: onb_init_from_uw()\n");

	// Test onb_init_from_wu()
	basis = onb_init_from_wu(w, u);
	assert(tuple_equal(basis.u, (t_tuple) {1.0, 0.0, 0.0}));
	assert(tuple_equal(basis.w, (t_tuple) {0.0, 0.0, 1.0}));
	assert(is_approx_equal(tuple_dot(basis.u, basis.v), 0.0, 1e-6));
	assert(is_approx_equal(tuple_dot(basis.u, basis.w), 0.0, 1e-6));
	assert(is_approx_equal(tuple_dot(basis.v, basis.w), 0.0, 1e-6));
	printf("\033[1;92mTest passed\033[0;39m: onb_init_from_wu()\n");

	// Test onb_init_from_vw()
	basis = onb_init_from_vw(v, w);
	assert(tuple_equal(basis.v, (t_tuple) {0.0, 1.0, 0.0}));
	assert(tuple_equal(basis.w, (t_tuple) {0.0, 0.0, 1.0}));
	assert(is_approx_equal(tuple_dot(basis.u, basis.v), 0.0, 1e-6));
	assert(is_approx_equal(tuple_dot(basis.u, basis.w), 0.0, 1e-6));
	assert(is_approx_equal(tuple_dot(basis.v, basis.w), 0.0, 1e-6));
	printf("\033[1;92mTest passed\033[0;39m: onb_init_from_vw()\n");

	// Test onb_init_from_wv()
	basis = onb_init_from_wv(w, v);
	assert(tuple_equal(basis.v, (t_tuple) {0.0, 1.0, 0.0}));
	assert(tuple_equal(basis.w, (t_tuple) {0.0, 0.0, 1.0}));
	assert(is_approx_equal(tuple_dot(basis.u, basis.v), 0.0, 1e-6));
	assert(is_approx_equal(tuple_dot(basis.u, basis.w), 0.0, 1e-6));
	assert(is_approx_equal(tuple_dot(basis.v, basis.w), 0.0, 1e-6));
	printf("\033[1;92mTest passed\033[0;39m: onb_init_from_wv()\n");

}