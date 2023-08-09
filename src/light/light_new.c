/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:13:10 by arobu             #+#    #+#             */
/*   Updated: 2023/08/09 19:13:10 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_light	light_new(t_tuple origin, t_color intensity)
{
	return ((t_light){origin, intensity});
}