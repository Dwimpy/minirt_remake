/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:13:22 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/09 17:19:34 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "hooks.h"
#include "parser.h"
#include "libft.h"
#include "cylinder.h"
#include "scene.h"


void	create_cylinder(t_scene *scene)
{
	t_shape	cylinder;

	cylinder = shape_new_cylinder(1, 5, 4);
	cylinder.material = material_default(color_multiply_s \
						(color_new(5, 255, 5), (1.0 / 255.0)));
	cylinder.material.color = color_multiply(cylinder.material.color, \
							color_multiply_s(color_new(255.0, 255.0, 255.0), \
							(1.0 / 255.0) * 0.1));
	shape_translate(&cylinder, 25, 25, 25);
	// shape_rotate(&cylinder, 0, 0, 35);
	shape_scale(&cylinder, 25, 25, 25);
	tf_compute(&cylinder.transform);
	vector_pushback(&scene->objs, &cylinder);
}
