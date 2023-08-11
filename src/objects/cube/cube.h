/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:29:53 by arobu             #+#    #+#             */
/*   Updated: 2023/08/11 21:29:53 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# define CUBE_MEM_ALLOCATION_FAILED\
			"Cube memory allocation failed. Exiting.\n"

# include "tuple.h"
# include "intersect.h"
# include "vector.h"
# include "shape.h"
# include <stdarg.h>

typedef struct s_cube_intersect
{
	t_real		x[2];
	t_real		y[2];
	t_real		z[2];
}				t_cube_intersect;

typedef struct s_cube
{
	t_tuple		origin;
}				t_cube;

t_shape		shape_new_cube(void);
void		cube_print(t_shape *shape);
bool		cube_intersect(t_shape *shape, t_ray ray, t_vector *intersections);
t_tuple		cube_normal_at(t_shape *shape, t_tuple isec_point);
void		cube_tests(void);
t_real		cube_bounds_get(int min_max, size_t count, ...);
#endif