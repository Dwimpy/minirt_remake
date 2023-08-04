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
#include "light.h"
#include "tuple.h"
#include "vector.h"

t_color light_lightning(t_material material, t_light light, t_tuple point, t_tuple eye, t_tuple normal) {
	t_color e_color;
	t_tuple light_v;
	t_real	light_dot;
	t_color	ambient;
	t_color	diffuse;
	t_color	specular;
	t_tuple	reflectv;
	t_real	reflect_dot_eye;
	t_real	factor;

	e_color = color_multiply(material.color, light.intensity);
	light_v = tuple_normalize(tuple_subtract(light.origin, point));
	light_dot = tuple_dot(light_v, normal);
	ambient = color_multiply_s(e_color, material.ambient);
	if (light_dot < 0)
	{
		diffuse = color_new(0.0, 0.0, 0.0);
		specular = color_new(0.0, 0.0, 0.0);
	}
	else
		diffuse = color_multiply_s(color_multiply_s(e_color, material.diffuse), light_dot);
	reflectv = tuple_reflect(tuple_negate(light_v), normal);
	reflect_dot_eye = tuple_dot(reflectv, eye);
	if (reflect_dot_eye <= 0)
		specular = color_new(0.0 ,0.0 ,0.0);
	else
	{
		factor = pow(reflect_dot_eye, material.shininess);
		specular = color_multiply_s(color_multiply_s(light.intensity, material.specular), factor);
	}
	return (color_add(color_add(ambient, diffuse), specular));
}