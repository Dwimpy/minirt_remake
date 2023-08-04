/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:37:50 by arobu             #+#    #+#             */
/*   Updated: 2023/08/04 18:37:50 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H
#include "color.h"
# include "tuple.h"

typedef struct s_material
{
	t_real		ambient;
	t_real		diffuse;
	t_real		specular;
	t_real		shininess;
	t_real		emission;
	t_color		color;
}				t_material;

t_material	default_material(t_color color);

#endif