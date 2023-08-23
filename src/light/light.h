/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:05:24 by arobu             #+#    #+#             */
/*   Updated: 2023/08/23 13:41:43 by arobu            ###   ########.fr       */
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
# include "shape.h"

typedef struct s_computations	t_computations;

typedef enum e_light_type
{
	POINT_LIGHT,
	RECT_LIGHT
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
	t_tuple			origin;
	t_color			intensity;
	size_t			samples;
	t_light_type	type;
	void			*data;
}					t_light;

typedef struct s_phong_params
{
	t_color	eff_color;
	t_color	ambient;
	t_color	diffuse;
	t_color	specular;
	t_tuple	light_dir;
	t_tuple	reflect;
	t_real	light_dot_normal;
	t_real	reflect_dot_eye;
	t_real	factor;
	t_color	black;
}				t_phong_params;

typedef struct s_rect_light_params
{
	t_tuple		origin;
	t_color		intensity;
	t_tuple		normal;
	t_coord		width_height;
	size_t		samples;
}				t_rect_light_params;

t_light	light_point_new(t_tuple origin, t_color intensity);
t_light	light_rect_new(t_rect_light_params p);
t_real	light_intensity_at(t_scene *world, t_light *light, t_tuple *point);
t_real	light_intensity_at_threads(\
	t_scene *world, t_light *light, t_tuple *point, t_thread_isect *isect);
t_color	light_lightning(t_computations *comps, t_light *light);
t_tuple	light_point_on(t_light *light, size_t x, size_t y);

#endif