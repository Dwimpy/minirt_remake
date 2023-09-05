/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:03:31 by arobu             #+#    #+#             */
/*   Updated: 2023/09/05 15:49:19 by apaghera         ###   ########.fr       */
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

typedef void			(*t_shape_print)(t_shape *shape);
typedef bool			(*t_shape_intersect)(t_shape *shape, \
						t_ray ray, t_vector *intersections);
typedef t_tuple			(*t_shape_normal_at)(t_shape *shape, \
						t_tuple isec_point);

typedef struct s_shape_vtable
{
	t_shape_print			print;
	t_shape_intersect		intersect;
	t_shape_normal_at		normal_at;
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
void		shape_reset(t_shape *shape);
t_material	shape_get_material(const t_shape *shape);
t_color		shape_get_color(const t_shape *shape);
void		shape_translate(t_shape *shape, double x, double y, double z);
void		shape_scale(t_shape *shape, double x, double y, double z);
void		shape_rotate_x(t_shape *shape, double z);
void		shape_rotate_y(t_shape *shape, double z);
void		shape_rotate_z(t_shape *shape, double z);
void		shape_rotate(t_shape *shape, double x, double y, double z);
void		shape_free(t_shape *shape);

#endif
