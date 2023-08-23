/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:21:11 by arobu             #+#    #+#             */
/*   Updated: 2023/08/18 16:51:08 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#ifndef TUPLE_H
# define TUPLE_H
# define M_EPSILON 1e-4
# define M_INFINITY 1e10

# include "libft.h"
# include "stdio.h"
# include "math.h"
# include "stdbool.h"

typedef double	t_real;

typedef struct s_coord
{
	t_real		x;
	t_real		y;
}				t_coord;

typedef struct s_tuple
{
	t_real		x;
	t_real		y;
	t_real		z;
	t_real		w;
}				t_tuple;

// Tuple functionality

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

t_real	clamp(t_real n, t_real min, t_real max);

bool	tuple_equal(t_tuple v, t_tuple res);
bool	tuple_equal_s(t_tuple v, t_real s);
bool	is_approx_equal(t_real a, t_real b, t_real epsilon);
bool	tuple_equal_p(t_tuple v, t_tuple res, t_real precision);

void	tuple_print(t_tuple v);
t_tuple	tuple_print_ret(t_tuple v);

// Coord functions

t_coord	coord_new(t_real x, t_real y);

#endif
