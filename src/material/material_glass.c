/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_glass.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:13:20 by arobu             #+#    #+#             */
/*   Updated: 2023/09/20 11:46:02 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "material.h"
#include "tuple.h"

t_material	material_glass(t_color color)
{
	t_material	material;

	material.color = color_multiply_s(color, 1 / 255.0);
	material.transparency = 0.9;
	material.reflectivity = 0.1;
	material.specular = 0.9;
	material.shininess = 300;
	material.ambient = 0.1;
	material.diffuse = 0.0;
	material.refractive_index = 1.52;
	return (material);
}
