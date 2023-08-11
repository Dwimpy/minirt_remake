/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_default.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:47:03 by arobu             #+#    #+#             */
/*   Updated: 2023/08/04 18:47:03 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"

t_material	material_default(t_color color)
{
	t_material	material;

	material.ambient = 0.1;
	material.diffuse = 0.9;
	material.specular = 1.0;
	material.shininess = 200;
	material.refractive_index = 1.0;
	material.reflectivity = 0.0;
	material.color = color;
	return (material);
}