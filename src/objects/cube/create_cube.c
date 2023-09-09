/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cube.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:46:21 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/09 16:54:29 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "hooks.h"
#include "parser.h"
#include "libft.h"
#include "cube.h"
#include "scene.h"

void	create_cube(t_scene *scene)
{
	t_shape	cube;

	cube = shape_new_cube();
	cube.material = material_default(color_multiply_s \
						(color_new(5, 255, 5), (1.0 / 255.0)));
	cube.material.color = color_multiply(cube.material.color, \
							color_multiply_s(color_new(255.0, 255.0, 255.0), \
							(1.0 / 255.0) * 0.1));
	shape_translate(&cube, 50, 50, 50);
	// shape_rotate(&cube, 0, 0, 35);
	shape_scale(&cube, 25, 25, 25);
	tf_compute(&cube.transform);
	vector_pushback(&scene->objs, &cube);
}
