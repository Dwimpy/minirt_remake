/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:00:11 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/11 14:48:53 by apaghera         ###   ########.fr       */
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
	t_shape	plane;

	plane = shape_new_plane();
	plane.material = material_color_apply(vector, idx, 3);
	plane.material.color = color_apply(plane, vector, 3, 2);
	shape_translate(&plane, 0, 0, 0);
	shape_rotate(&plane, 0, 0, 35);
	shape_scale(&plane, 0, 0, 0);
	tf_compute(&plane.transform);
	vector_pushback(&scene->objs, &plane);
}
