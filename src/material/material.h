/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:37:50 by arobu             #+#    #+#             */
/*   Updated: 2023/09/25 10:20:21 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H
# include "color.h"
# include "tuple.h"
# include "vector.h"

typedef enum e_material_result
{
	MATERIAL_SUCCESS,
	INVALID_INPUT,
	INVALID_TYPE,
	INVALID_AMOUNT,
}	t_material_result;

typedef struct s_material
{
	t_real		ambient;
	t_real		diffuse;
	t_real		specular;
	t_real		shininess;
	t_real		reflectivity;
	t_real		refractive_index;
	t_real		transparency;
	t_color		color;
}				t_material;

t_material			material_default(t_color color);
t_material			material_lambertian(t_color color);
t_material			material_glass(t_color color);
t_material			material_copper(void);
t_material			material_color_apply(t_vector vector, int idx, int column);
t_material_result	def_material(char **str, t_color color, \
									int column, t_material *material);
#endif