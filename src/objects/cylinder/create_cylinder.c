/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:13:22 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/12 16:21:54 by apaghera         ###   ########.fr       */
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

	cylinder = shape_new_cylinder(-1, 1, true);
	cylinder.material = material_color_apply(vector, idx, 3);
	cylinder.material.color = color_apply(cylinder, vector, 3, 2);
	shape_translate(&cylinder, 5, 5, 5);
	shape_rotate(&cylinder, 0, 0, 90);
	shape_scale(&cylinder, 10, 25, 10);
	tf_compute(&cylinder.transform);
	vector_pushback(&scene->objs, &cylinder);
}
