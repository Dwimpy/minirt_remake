/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_cuboid_new.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:54:53 by arobu             #+#    #+#             */
/*   Updated: 2023/08/15 15:54:53 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "libft.h"
#include "light.h"
#include "light_cuboid.h"
#include "pdf_cuboid.h"

t_light	light_cuboid_new(t_tuple origin, t_color intensity, t_tuple dimension)
{
	t_light			light;
	t_light_cuboid	*light_cuboid;

	light_cuboid = ft_calloc(1, sizeof(t_light_cuboid));
	if (!light_cuboid)
	{
		printf("Memory allocation failed\n. Exiting.");
		exit (1);
	}
	light_cuboid->dimension = dimension;
	light.pdf = pdf_new_cuboid(dimension);
	light.data = light_cuboid;
	light.origin = origin;
	light.intensity = intensity;
	light.type = CUBOID_LIGHT;
	return (light);
}