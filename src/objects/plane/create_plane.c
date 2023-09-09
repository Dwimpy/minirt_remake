/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:00:11 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/09 17:12:05 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "hooks.h"
#include "parser.h"
#include "libft.h"
#include "plane.h"
#include "scene.h"

void	create_plane(t_scene *scene)
{
	t_shape	plane;

	plane = shape_new_plane();
	plane.material = material_default(color_multiply_s \
						(color_new(255, 255, 5), (1.0 / 255.0)));
	plane.material.color = color_multiply(plane.material.color, \
							color_multiply_s(color_new(255.0, 255.0, 255.0), \
							(1.0 / 255.0) * 0.1));
	shape_translate(&plane, 0, 0, 0);
	shape_rotate(&plane, 0, 0, 35);
	shape_scale(&plane, 0, 0, 0);
	tf_compute(&plane.transform);
	vector_pushback(&scene->objs, &plane);
}
