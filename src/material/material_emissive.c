/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_emissive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:38:48 by arobu             #+#    #+#             */
/*   Updated: 2023/08/16 16:38:48 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"

t_material material_emissive(t_color color)
{
	t_material	material;

	material.ambient = 0.0;
	material.diffuse = 0.0;
	material.specular = 0.0;
	material.shininess = 0.0;
	material.refractive_index = 0.0;
	material.reflectivity = 0.0;
	material.transparency = 0.0;
	material.is_emissive = true;
	material.color = color;
	return (material);
}