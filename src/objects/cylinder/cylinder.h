/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:35:15 by arobu             #+#    #+#             */
/*   Updated: 2023/08/23 16:48:20 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H
# define CYLINDER_MEM_ALLOCATION_FAILED\
			"Cylinder memory allocation failed. Exiting.\n"

# include "tuple.h"
# include "intersect.h"
# include "vector.h"
# include "shape.h"
# include <stdarg.h>

typedef struct s_cyl_bounds
{
	t_real		y_min;
	t_real		y_max;
}				t_cyl_bounds;

typedef struct s_cylinder
{
	t_tuple			origin;
	t_cyl_bounds	bounds;
	bool			capped;
}				t_cylinder;

t_shape		shape_new_cylinder(t_real y_min, t_real y_max, bool capped);
void		cylinder_print(t_shape *shape);
bool		cylinder_intersect(\
	t_shape *shape, t_ray ray, t_vector *intersections);
t_tuple		cylinder_normal_at(t_shape *shape, t_tuple isec_point);
bool		cylinder_is_in_cap(t_ray *ray, t_real const *t);

#endif
