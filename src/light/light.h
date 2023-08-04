/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:05:24 by arobu             #+#    #+#             */
/*   Updated: 2023/08/04 19:05:24 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "material.h"
# include "tuple.h"
# include "color.h"

typedef struct s_light
{
	t_tuple		origin;
	t_color		intensity;
}				t_light;

t_color	light_lightning(t_material material, t_light light, t_tuple point, t_tuple eye, t_tuple normal);

#endif