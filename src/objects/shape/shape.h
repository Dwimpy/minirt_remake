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

#include <stdbool.h>
#include "ray.h"
#include "color.h"

typedef struct s_shape	t_shape;

typedef struct s_hit_record
{
	t_real		t;
	t_tuple		normal;
	t_color		color;
	t_shape 	*shape;
}				t_hit_record;

typedef struct s_shape_vtable
{
	void		*(*get_data)(t_shape *shape);
	void		(*print)(t_shape *shape);
	bool		(*hit)(t_ray ray, t_real tmin, t_real tmax, t_hit_record *hit_rec);
	bool		(*shadow_hit)(t_ray ray, t_real tmin, t_real tmax, t_hit_record *hit_rec);
}				t_shape_vtable;

typedef struct s_shape
{
	t_shape_vtable	vtable;
	void			*data;
}				t_shape;

#endif