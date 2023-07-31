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
	t_vec3 u = {1.0, 0.0, 0.0};
	t_vec3 v = {0.0, 1.0, 0.0};
	t_vec3 w = {0.0, 0.0, 1.0};

	// Test onb_init_from_u()
	t_onb basis = onb_init_from_u(u);
	assert(vec3_equal(basis.u, (t_vec3){1.0, 0.0, 0.0}));
	assert(is_approx_equal(vec3_dot(basis.u, basis.v), 0.0, 1e-6));
	assert(is_approx_equal(vec3_dot(basis.u, basis.w), 0.0, 1e-6));
	assert(is_approx_equal(vec3_dot(basis.v, basis.w), 0.0, 1e-6));
	printf("\033[1;92mTest passed\033[0;39m: onb_init_from_u()\n");

	// Test onb_init_from_v()
	basis = onb_init_from_v(v);
	assert(vec3_equal(basis.v, (t_vec3){0.0, 1.0, 0.0}));
	assert(is_approx_equal(vec3_dot(basis.u, basis.v), 0.0, 1e-6));
	assert(is_approx_equal(vec3_dot(basis.v, basis.w), 0.0, 1e-6));
	assert(is_approx_equal(vec3_dot(basis.u, basis.w), 0.0, 1e-6));
	printf("\033[1;92mTest passed\033[0;39m: onb_init_from_v()\n");

	// Test onb_init_from_w()
	basis = onb_init_from_w(w);
	assert(vec3_equal(basis.w, (t_vec3){0.0, 0.0, 1.0}));
	assert(is_approx_equal(vec3_dot(basis.u, basis.w), 0.0, 1e-6));
	assert(is_approx_equal(vec3_dot(basis.v, basis.w), 0.0, 1e-6));
	assert(is_approx_equal(vec3_dot(basis.u, basis.v), 0.0, 1e-6));
	printf("\033[1;92mTest passed\033[0;39m: onb_init_from_w()\n");

	// Test onb_init_from_uv()
	basis = onb_init_from_uv(u, v);
	assert(vec3_equal(basis.u, (t_vec3){1.0, 0.0, 0.0}));
	assert(vec3_equal(basis.v, (t_vec3){0.0, 1.0, 0.0}));
	assert(is_approx_equal(vec3_dot(basis.u, basis.v), 0.0, 1e-6));
	assert(is_approx_equal(vec3_dot(basis.u, basis.w), 0.0, 1e-6));
	assert(is_approx_equal(vec3_dot(basis.v, basis.w), 0.0, 1e-6));
	printf("\033[1;92mTest passed\033[0;39m: onb_init_from_uv()\n");

	// Test onb_init_from_vu()
	basis = onb_init_from_vu(v, u);
	assert(vec3_equal(basis.u, (t_vec3){1.0, 0.0, 0.0}));
	assert(vec3_equal(basis.v, (t_vec3){0.0, 1.0, 0.0}));
	assert(is_approx_equal(vec3_dot(basis.u, basis.v), 0.0, 1e-6));
	assert(is_approx_equal(vec3_dot(basis.u, basis.w), 0.0, 1e-6));
	assert(is_approx_equal(vec3_dot(basis.v, basis.w), 0.0, 1e-6));
	printf("\033[1;92mTest passed\033[0;39m: onb_init_from_vu()\n");

	// Test onb_init_from_uw()
	basis = onb_init_from_uw(u, w);
	assert(vec3_equal(basis.u, (t_vec3){1.0, 0.0, 0.0}));
	assert(vec3_equal(basis.w, (t_vec3){0.0, 0.0, 1.0}));
	assert(is_approx_equal(vec3_dot(basis.u, basis.v), 0.0, 1e-6));
	assert(is_approx_equal(vec3_dot(basis.u, basis.w), 0.0, 1e-6));
	assert(is_approx_equal(vec3_dot(basis.v, basis.w), 0.0, 1e-6));
	printf("\033[1;92mTest passed\033[0;39m: onb_init_from_uw()\n");

	// Test onb_init_from_wu()
	basis = onb_init_from_wu(w, u);
	assert(vec3_equal(basis.u, (t_vec3){1.0, 0.0, 0.0}));
	assert(vec3_equal(basis.w, (t_vec3){0.0, 0.0, 1.0}));
	assert(is_approx_equal(vec3_dot(basis.u, basis.v), 0.0, 1e-6));
	assert(is_approx_equal(vec3_dot(basis.u, basis.w), 0.0, 1e-6));
	assert(is_approx_equal(vec3_dot(basis.v, basis.w), 0.0, 1e-6));
	printf("\033[1;92mTest passed\033[0;39m: onb_init_from_wu()\n");

	// Test onb_init_from_vw()
	basis = onb_init_from_vw(v, w);
	assert(vec3_equal(basis.v, (t_vec3){0.0, 1.0, 0.0}));
	assert(vec3_equal(basis.w, (t_vec3){0.0, 0.0, 1.0}));
	assert(is_approx_equal(vec3_dot(basis.u, basis.v), 0.0, 1e-6));
	assert(is_approx_equal(vec3_dot(basis.u, basis.w), 0.0, 1e-6));
	assert(is_approx_equal(vec3_dot(basis.v, basis.w), 0.0, 1e-6));
	printf("\033[1;92mTest passed\033[0;39m: onb_init_from_vw()\n");

	// Test onb_init_from_wv()
	basis = onb_init_from_wv(w, v);
	assert(vec3_equal(basis.v, (t_vec3){0.0, 1.0, 0.0}));
	assert(vec3_equal(basis.w, (t_vec3){0.0, 0.0, 1.0}));
	assert(is_approx_equal(vec3_dot(basis.u, basis.v), 0.0, 1e-6));
	assert(is_approx_equal(vec3_dot(basis.u, basis.w), 0.0, 1e-6));
	assert(is_approx_equal(vec3_dot(basis.v, basis.w), 0.0, 1e-6));
	printf("\033[1;92mTest passed\033[0;39m: onb_init_from_wv()\n");

}