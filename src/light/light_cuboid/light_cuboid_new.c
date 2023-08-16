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
#include "material.h"
#include "onb.h"
#include "pdf.h"
#include "pdf_cuboid.h"
#include "cube.h"

t_light	light_cuboid_new(t_color intensity, t_tuple dimension)
{
	t_light	light;

	light.shape = shape_new_cube();
	shape_scale(\
		&light.shape, dimension.x / 2.0, dimension.y / 2.0, dimension.z / 2.0);
	light.shape.material = material_emissive(intensity);
	light.pdf = pdf_new_cuboid(dimension);
	light.onb = onb_create_left(tuple_new_vector(0, 1, 0));
	light.onb.forward = tuple_negate(light.onb.forward);
	light.intensity = intensity;
	light.dimension = dimension;
	light.type = CUBOID_LIGHT;
	light.pdf.sample = pdf_sample_cuboid;
	return (light);
}