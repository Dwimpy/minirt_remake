/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                           :+:      :+:    :+:   */
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

typedef struct s_tuple
{
	t_real		x;
	t_real		y;
	t_real		z;
	t_real		w;
}				t_tuple;

t_tuple	tuple_vector_zero(void);
t_tuple	tuple_point_zero(void);
t_tuple	tuple_new_vector(t_real x, t_real y, t_real z);
t_tuple	tuple_new_point(t_real x, t_real y, t_real z);
t_tuple	tuple_add(t_tuple v1, t_tuple v2);
t_tuple	tuple_subtract(t_tuple v1, t_tuple v2);
t_tuple	tuple_multiply(t_tuple v1, t_tuple v2);
t_tuple	tuple_multiply_s(t_tuple v, t_real s);
t_tuple	tuple_division(t_tuple v1, t_tuple v2);
t_tuple	tuple_division_s(t_tuple v1, t_real s);
t_tuple	tuple_negate(t_tuple v);
t_tuple	tuple_clamp(t_tuple v, t_real min, t_real max);
t_tuple	tuple_cross(t_tuple v1, t_tuple v2);
t_tuple	tuple_normalize(t_tuple v);
t_tuple	tuple_reflect(t_tuple v, t_tuple n);
t_real	tuple_dot(t_tuple v1, t_tuple v2);
t_real	tuple_magnitude(t_tuple v);
t_real	tuple_magnitude_squared(t_tuple v);

void	tuple_set(t_tuple *tuple, t_real x, t_real y, t_real z);

t_real	clamp(t_real n, double min, double max);

bool	tuple_equal(t_tuple v, t_tuple res);
bool	tuple_equal_s(t_tuple v, t_real s);
bool	is_approx_equal(t_real a, t_real b, t_real epsilon);

void	tuple_print(t_tuple v);
void	tuple_tests(void);

#endif