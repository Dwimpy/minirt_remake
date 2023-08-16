/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_lambertian.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 00:38:26 by arobu             #+#    #+#             */
/*   Updated: 2023/08/14 00:38:26 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"

t_material	material_lambertian(t_color color)
{
	t_material	material;

	material.ambient = 0.5;
	material.diffuse = 1.0;
	material.specular = 0.05;
	material.shininess = 200;
	material.refractive_index = 0.0;
	material.reflectivity = 0.007;
	material.transparency = 0.0;
	material.is_emissive = false;
	material.color = color;
	return (material);
}