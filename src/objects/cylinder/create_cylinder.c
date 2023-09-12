/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:13:22 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/11 15:44:11 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "hooks.h"
#include "parser.h"
#include "libft.h"
#include "cylinder.h"
#include "scene.h"


void	create_cylinder(t_vector vector, t_scene *scene, int idx)
{
	t_shape	cylinder;

	cylinder = shape_new_cylinder(0, 1, false);
	cylinder.material = material_color_apply(vector, idx, 3);
	cylinder.material.color = color_apply(cylinder, vector, 3, 2);
	shape_translate(&cylinder, 0, -25, 0);
	// shape_rotate(&cylinder, 0, 0, 35);
	shape_scale(&cylinder, 25, 25, 25);
	tf_compute(&cylinder.transform);
	vector_pushback(&scene->objs, &cylinder);
}
