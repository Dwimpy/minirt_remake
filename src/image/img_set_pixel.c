/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_set_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 22:51:33 by arobu             #+#    #+#             */
/*   Updated: 2023/08/17 21:55:31 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "color.h"
#include "image.h"
#include <stdint.h>

void	image_set_pixel(t_image *image, t_color c, uint32_t i, uint32_t j)
{
	uint32_t	color;

	c.x = pow(c.x, 0.45454545454);
	c.y = pow(c.y, 0.45454545454);
	c.z = pow(c.z, 0.45454545454);
	c = color_clamp(c);
	c = color_multiply_s(c, (uint32_t) 256.0);
	color = get_rgba((uint32_t)c.x, (uint32_t)c.y, (uint32_t)c.z);
	mlx_put_pixel(image->buffer, i, j, color);
}