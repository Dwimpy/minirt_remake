/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:13:22 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/19 12:05:26 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "hooks.h"
#include "parser.h"
#include "libft.h"
#include "cylinder.h"
#include "scene.h"


void	rotation_obj(t_vector *vector, t_shape *obj, int idx, int column)
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
		shape_rotate(obj, x, y, z);
		free_double_arr(values);
	}
}

void	diam_height_obj(t_vector *vector, t_shape *obj, int idx, int column)
{
	double	x;
	double	y;
	double	z;
	char	**str;
	char	**values;

	str = *(char ***)vector_at(vector, idx);
	if (str[column])
	{
		x = ft_atof(str[column]);
		z = ft_atof(str[column]);
		if (str[column + 1])
		{
			y = ft_atof(str[column + 1]);
			shape_scale(obj, x, y, z);
		}
	}
}

void	create_cylinder(t_vector vector, t_scene *scene, int idx)
{
	t_shape				cylinder;
	t_material_result	result;
	char				**str;

	cylinder = shape_new_cylinder(-1, 1, true);
	str = *(char ***)vector_at(&vector, idx);
	result = def_material(str, parse_vector(&vector, idx, 5), 6, &cylinder.material);
	if (result != MATERIAL_SUCCESS)
	{
		cylinder.material = material_color_apply(vector, idx, 5);
		cylinder.material.color = color_apply(cylinder, vector, 3, 2);
	}
	position_obj(&vector, &cylinder, idx, 1);
	diam_height_obj(&vector, &cylinder, idx, 3);
	rotation_obj(&vector, &cylinder, idx, 2);
	tf_compute(&cylinder.transform);
	vector_pushback(&scene->objs, &cylinder);
}
