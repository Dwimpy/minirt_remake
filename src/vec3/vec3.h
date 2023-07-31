/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:14:11 by arobu             #+#    #+#             */
/*   Updated: 2023/07/30 18:14:11 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H
# define M_EPSILON 1e-6
# define M_INFINITY 1e10

# include "libft.h"
# include "stdio.h"
# include "math.h"
# include "stdbool.h"

typedef double	t_real;

typedef struct s_coord
{
	t_real		u;
	t_real		v;
}				t_coord;

typedef struct s_vec3
{
	t_real		x;
	t_real		y;
	t_real		z;
}				t_vec3;

t_vec3	vec3_zero(void);
t_vec3	vec3_create(t_real x, t_real y, t_real z);
t_vec3	vec3_add(t_vec3 v1, t_vec3 v2);
t_vec3	vec3_subtract(t_vec3 v1, t_vec3 v2);
t_vec3	vec3_multiply(t_vec3 v1, t_vec3 v2);
t_vec3	vec3_multiply_s(t_vec3 v, t_real s);
t_vec3	vec3_division(t_vec3 v1, t_vec3 v2);
t_vec3	vec3_division_s(t_vec3 v1, t_real s);
t_vec3	vec3_negate(t_vec3 v);
t_vec3	vec3_clamp(t_vec3 v, t_real min, t_real max);
t_vec3	vec3_cross(t_vec3 v1, t_vec3 v2);
t_vec3	vec3_normalize(t_vec3 v);
t_real	vec3_dot(t_vec3 v1, t_vec3 v2);
t_real	vec3_magnitude(t_vec3 v);
t_real	vec3_magnitude_squared(t_vec3 v);

t_real	clamp(t_real n, double min, double max);

bool	vec3_equal(t_vec3 v, t_vec3 res);
bool	vec3_equal_s(t_vec3 v, t_real s);
bool	is_approx_equal(t_real a, t_real b, t_real epsilon);

void	vec3_print(t_vec3 v);
void	vec3_test(void);

#endif