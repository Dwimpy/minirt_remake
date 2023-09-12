/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:23:07 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/10 18:50:54 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "hooks.h"
#include "parser.h"
#include "libft.h"
#include "sphere.h"
#include "scene.h"

t_material	material_color_apply(t_vector vector, int idx, int column)
{
	t_color	color;

	color = parse_vector(&vector, idx, column);
	return (material_default(color_multiply_s \
						(color, (1.0 / 255.0))));
}

t_color	color_apply(t_shape shape, t_vector vector, int idx, int column)
{
	t_tuple	color;
	double	ambient;
	char	**str;

	str = *(char ***)vector_at(&vector, idx);
	ambient = ft_atof(str[1]);
	color = parse_vector(&vector, idx, column);
	return (color_multiply(shape.material.color, \
							color_multiply_s(color, \
							(1.0 / 255.0) * ambient)));
}

void	create_sphere(t_vector vector, t_scene *scene, int idx)
{
	t_shape	sphere;

	sphere = shape_new_sphere();
	sphere.material = material_color_apply(vector, idx, 3);
	sphere.material.color = color_apply(sphere, vector, 3, 2);
	shape_translate(&sphere, 0, 0, 0);
	// shape_rotate(&sphere, 0, 0, 35);
	shape_scale(&sphere, 25, 25, 25);
	tf_compute(&sphere.transform);
	vector_pushback(&scene->objs, &sphere);
}
