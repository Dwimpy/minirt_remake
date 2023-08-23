/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_add_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:36:04 by arobu             #+#    #+#             */
/*   Updated: 2023/08/23 13:06:57 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "window.h"

void	window_add_image(mlx_t *mlx, t_image *image)
{
	image_create(mlx, image, mlx->width, mlx->height);
	ft_memset(image->buffer->pixels, 0, \
		sizeof(uint32_t) * image->width * image->height);
	mlx_image_to_window(mlx, image->buffer, 0, 0);
}
