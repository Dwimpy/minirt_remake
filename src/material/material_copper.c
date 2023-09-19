/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_metal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:41:38 by arobu             #+#    #+#             */
/*   Updated: 2023/08/17 20:52:36 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"

t_material	material_copper(void)
{
	t_material	material;

	material.color = color_new(0.95, 0.64, 0.54);
	material.ambient = 0.1;
	material.diffuse = 0.9;
	material.specular = 0.9;
	material.shininess = 270;
	material.refractive_index = 1.0;
	material.reflectivity = 1.0;
	material.transparency = 0.0;
	return (material);
}
