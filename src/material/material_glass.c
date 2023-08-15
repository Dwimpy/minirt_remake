/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_glass.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:13:20 by arobu             #+#    #+#             */
/*   Updated: 2023/08/09 05:37:34 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "material.h"

t_material material_glass(void)
{
	t_material	material;

	material = material_default(color_new(0.529, 0.808, 0.922));
	material.transparency = 0.9;
	material.reflectivity = 0.05;
	material.specular = 0.9;
	material.shininess = 250;
	material.ambient = 0.1;
	material.diffuse = 0.0;
	material.refractive_index = 1.52;
	return (material);
}
