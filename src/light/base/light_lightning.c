/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_lightning.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:10:26 by arobu             #+#    #+#             */
/*   Updated: 2023/08/04 19:10:26 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "intersect.h"
#include "light.h"
#include "shape.h"
#include "tuple.h"

t_color	light_lightning(t_computations *comps, t_light *light)
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
	t_material	m;

	m = comps->shape->material;
	eff_color = color_multiply(m.color, light->intensity);
	light_dir = tuple_normalize(\
				tuple_subtract(light->origin, comps->over_point));
	ambient = color_multiply_s(eff_color, m.ambient);
	light_dot_normal = tuple_dot(light_dir, comps->normal);
	reflect_dot_eye = 0.0;
	black = color_new(0.0, 0.0, 0.0);
	specular = black;
	diffuse = black;
	if (comps->is_shadowed)
		return (ambient);
	if (light_dot_normal < 0.0)
	{
		diffuse = black;
		specular = black;
	}
	else
	{
		diffuse = color_multiply_s(eff_color, m.diffuse * light_dot_normal);
		reflect = tuple_reflect(tuple_negate(light_dir), comps->normal);
		reflect_dot_eye = tuple_dot(reflect, comps->eye);
		if (reflect_dot_eye <= 0.0)
			specular = black;
		else
		{
			factor = pow(reflect_dot_eye, m.shininess);
			specular = color_multiply_s(light->intensity, m.specular * factor);
		}
	}
	return (color_add(color_add(ambient, diffuse), specular));
}

t_color	light_tests(t_material *m, t_light *light, t_tuple point, t_tuple eye, t_tuple normal)
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

	eff_color = color_multiply(m->color, light->intensity);
	light_dir = tuple_normalize(tuple_subtract(light->origin, point));
	ambient = color_multiply_s(eff_color, m->ambient);
	light_dot_normal = tuple_dot(light_dir, normal);
	reflect_dot_eye = 0.0;
	black = color_new(0, 0, 0);
	specular = black;
	diffuse = black;
	if (light_dot_normal < 0.0)
	{
		diffuse = black;
		specular = black;
	}
	else
	{
		diffuse = color_multiply_s(eff_color, m->diffuse * light_dot_normal);
		reflect = tuple_reflect(tuple_negate(light_dir), normal);
		reflect_dot_eye = tuple_dot(reflect, eye);
		if (reflect_dot_eye <= 0)
			specular = black;
		else
		{
			factor = pow(reflect_dot_eye, m->shininess);
			specular = color_multiply_s(light->intensity, m->specular * factor);
		}
	}
	return (color_add(color_add(ambient, diffuse), specular));
}


