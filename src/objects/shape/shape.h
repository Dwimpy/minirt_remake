/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:03:31 by arobu             #+#    #+#             */
/*   Updated: 2023/08/01 15:03:31 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# include <stdbool.h>
# include "ray.h"
# include "color.h"
# include "transform.h"
# include "vector.h"
# include "intersect.h"
# include "material.h"


typedef struct s_shape	t_shape;

typedef struct s_shape_vtable
{
	void		(*print)(t_shape *shape);
	t_tuple		(*normal_at)(t_shape * shape, t_tuple isec_point);
	bool		(*intersect)(t_shape * shape, t_ray ray, \
					t_vector *intersections);
}				t_shape_vtable;

typedef struct s_shape
{
	t_shape_vtable	vtable;
	t_transform		transform;
	void			*data;
	t_material		material;
}				t_shape;

void		shape_set_transform(t_shape *shape, t_transform tf);
void		*shape_get_data(const t_shape *shape);
t_material	shape_get_material(const t_shape *shape);
t_color		shape_get_color(const t_shape *shape);

#endif