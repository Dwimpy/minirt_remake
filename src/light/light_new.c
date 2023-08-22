/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:55:43 by arobu             #+#    #+#             */
/*   Updated: 2023/08/14 23:33:12 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_light	light_point_new(t_tuple origin, t_color intensity)
{
	t_light	light;

	light.origin = origin;
	light.intensity = intensity;
	light.type = POINT_LIGHT;
	light.samples = 1;
	return (light);
}