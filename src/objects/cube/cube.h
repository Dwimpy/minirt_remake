/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:29:53 by arobu             #+#    #+#             */
/*   Updated: 2023/09/11 14:37:20 by apaghera         ###   ########.fr       */
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

typedef struct s_cube_computation
{
	double	max;
	double	abs_x;
	double	abs_y;
	double	abs_z;
	t_tuple	local_point;
	t_tuple	normal;
	t_tuple	world_normal;
}				t_cube_computation;

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
t_real		cube_bounds_get_max(size_t count, ...);
t_real		cube_bounds_get_min(size_t count, ...);
void		create_cube(t_vector vector, t_scene *scene, int idx);
#endif