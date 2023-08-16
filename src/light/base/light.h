/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:05:24 by arobu             #+#    #+#             */
/*   Updated: 2023/08/10 14:54:26 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "intersect.h"
# include "material.h"
#include "transform.h"
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

typedef struct s_light
{
	t_tuple			origin;
	t_onb			onb;
	t_light_type	type;
	t_color			intensity;
	t_pdf			pdf;
	t_tuple			dimension;
	t_shape			shape;
}				t_light;

t_light	point_light_new(t_tuple origin, t_color intensity);
t_light	light_cuboid_new(t_color intensity, t_tuple dimension);
t_color	light_lightning(t_computations *comps, t_light *light);
t_color	light_tests(t_material *m, t_light *light, t_tuple point, t_tuple eye, t_tuple normal);
#endif