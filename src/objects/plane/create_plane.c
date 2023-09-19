/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:00:11 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/19 13:16:03 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "hooks.h"
#include "parser.h"
#include "libft.h"
#include "plane.h"
#include "scene.h"

void	create_plane(t_vector vector, t_scene *scene, int idx)
{
	t_shape				plane;
	t_material_result	result;
	char				**str;

	plane = shape_new_plane();
	str = *(char ***)vector_at(&vector, idx);
	result = def_material(str, parse_vector(&vector, idx, 3), 4, &plane.material);
	if (result != MATERIAL_SUCCESS)
	{
		plane.material = material_color_apply(vector, idx, 3);
		plane.material.color = color_apply(plane, vector, 3, 2);
	}
	position_obj(&vector, &plane, idx, 1);
	rotation_obj(&vector, &plane, idx, 2);
	tf_compute(&plane.transform);
	vector_pushback(&scene->objs, &plane);
}
