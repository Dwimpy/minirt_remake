/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:23:07 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/09 16:41:51 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "hooks.h"
#include "parser.h"
#include "libft.h"
#include "sphere.h"
#include "scene.h"

void	create_sphere(t_scene *scene)
{
	t_shape	sphere;

	sphere = shape_new_sphere();
	sphere.material = material_default(color_multiply_s \
						(color_new(5, 255, 5), (1.0 / 255.0)));
	sphere.material.color = color_multiply(sphere.material.color, \
							color_multiply_s(color_new(255.0, 255.0, 255.0), \
							(1.0 / 255.0) * 0.1));
	shape_translate(&sphere, 0, 0, 0);
	// shape_rotate(&sphere, 0, 0, 35);
	shape_scale(&sphere, 25, 25, 25);
	tf_compute(&sphere.transform);
	vector_pushback(&scene->objs, &sphere);
}
