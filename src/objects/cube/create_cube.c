/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cube.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:46:21 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/11 14:37:06 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "hooks.h"
#include "parser.h"
#include "libft.h"
#include "cube.h"
#include "scene.h"



void	create_cube(t_vector vector, t_scene *scene, int idx)
{
	t_shape	cube;

	cube = shape_new_cube();
	cube.material = material_color_apply(vector, idx, 3);
	cube.material.color = color_apply(cube, vector, 3, 2);
	shape_translate(&cube, 50, 50, 50);
	// shape_rotate(&cube, 0, 0, 35);
	shape_scale(&cube, 25, 25, 25);
	tf_compute(&cube.transform);
	vector_pushback(&scene->objs, &cube);
}
