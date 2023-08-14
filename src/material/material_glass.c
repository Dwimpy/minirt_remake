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
	t_material material;

	material = material_default(color_new(1, 1, 1));
	material.transparency = 1.0;
	material.refractive_index = 1.5;
	return (material);
}