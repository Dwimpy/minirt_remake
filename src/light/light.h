/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:05:24 by arobu             #+#    #+#             */
/*   Updated: 2023/08/18 19:00:16 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "intersect.h"
# include "material.h"
# include "transform.h"
# include "tuple.h"
# include "color.h"
# include "onb.h"
# include "pdf.h"
# include "shape.h"

typedef struct s_computations	t_computations;

typedef enum e_light_type
{
	POINT_LIGHT,
	CUBOID_LIGHT
}			t_light_type;

typedef struct s_rect_light
{
	t_tuple		corner;
	t_coord		uv;
	t_tuple		up;
	t_tuple		right;
}				t_rect_light;

typedef struct s_light
{
	t_tuple		origin;
	t_color		intensity;
	void		*data;
}				t_light;

t_light	light_point_new(t_tuple origin, t_color intensity);
t_light	light_rect_new(t_tuple origin, t_color intensity, t_tuple normal, t_coord width_height);
t_real	light_intensity_at(t_scene *world, t_light *light, t_tuple *point);
t_color	light_lightning(t_computations *comps, t_light *light);
t_color	light_tests(t_material *m, t_light *light, t_tuple point, t_tuple eye, t_tuple normal, t_real intensity);
#endif