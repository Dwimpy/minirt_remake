/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:23:07 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/16 11:58:01 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "hooks.h"
#include "parser.h"
#include "libft.h"
#include "sphere.h"
#include "scene.h"

t_material	material_color_apply(t_vector vector, int idx, int column)
{
	t_color	color;

	color = parse_vector(&vector, idx, column);
	return (material_default(color_multiply_s \
						(color, (1.0 / 255.0))));
}

t_color	color_apply(t_shape shape, t_vector vector, int idx, int column)
{
	t_tuple	color;
	double	ambient;
	char	**str;

	str = *(char ***)vector_at(&vector, idx);
	ambient = ft_atof(str[1]);
	color = parse_vector(&vector, idx, column);
	return (color_multiply(shape.material.color, \
							color_multiply_s(color, \
							(1.0 / 255.0) * ambient)));
}

void	position_obj(t_vector *vector, t_shape *obj, int idx, int column)
{
	double	x;
	double	y;
	double	z;
	char	**str;
	char	**values;

	str = *(char ***)vector_at(vector, idx);
	if (view_from_to_valid(str[column]))
	{
		values = ft_split(str[column], ',');
		x = ft_atof(values[0]);
		y = ft_atof(values[1]);
		z = ft_atof(values[2]);
		shape_translate(obj, x, y, z);
		free_double_arr(values);
	}
}


void	sphere_cube_size(t_vector *vector, t_shape *obj, int idx, int column)
{
	double	radius;
	char	**str;

	str = *(char ***)vector_at(vector, idx);
	if (str[column])
	{
		radius = ft_atof(str[column]);
		shape_scale(obj, radius, radius, radius);
	}
}

void	create_sphere(t_vector vector, t_scene *scene, int idx)
{
	t_shape	sphere;

	sphere = shape_new_sphere();
	sphere.material = material_color_apply(vector, idx, 3);
	sphere.material.color = color_apply(sphere, vector, 3, 2);
	position_obj(&vector, &sphere, idx, 1);
	// shape_rotate(&sphere, 0, 0, 35);
	sphere_cube_size(&vector, &sphere, idx, 2);
	tf_compute(&sphere.transform);
	vector_pushback(&scene->objs, &sphere);
}
