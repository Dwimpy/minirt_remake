/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cube.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:46:21 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/20 11:02:21 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "hooks.h"
#include "parser.h"
#include "libft.h"
#include "cube.h"
#include "scene.h"
#include "sphere.h"

void	create_cube(t_vector vector, t_scene *scene, int idx)
{
	t_shape				cube;
	t_material_result	result;
	char				**str;

	cube = shape_new_cube();
	str = *(char ***)vector_at(&vector, idx);
	result = def_material(str, parse_vector(&vector, idx, 4), \
										5, &cube.material);
	if (result != MATERIAL_SUCCESS)
	{
		cube.material = material_color_apply(vector, idx, 4);
		cube.material.color = color_apply(cube, vector, 3, 2);
	}
	else
		cube.material.color = color_apply(cube, vector, 3, 2);
	position_obj(&vector, &cube, idx, 1);
	sphere_cube_size(&vector, &cube, idx, 2);
	rotation_obj(&vector, &cube, idx, 3);
	tf_compute(&cube.transform);
	vector_pushback(&scene->objs, &cube);
}
