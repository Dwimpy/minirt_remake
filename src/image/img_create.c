/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:08:19 by arobu             #+#    #+#             */
/*   Updated: 2023/07/31 17:08:19 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "image.h"
#include "stdlib.h"
#include "libft.h"
#include <stdint.h>

void	image_create(mlx_t *mlx, t_image *image, uint32_t width, uint32_t height)
{
	image->width = width;
	image->height = height;
	image->buffer = mlx_new_image(mlx, width, height);
	if (!image->buffer)
	{
		write(2, IMAGE_BUFFER_ALLOC_FAILED, 44);
		exit(EXIT_FAILURE);
	}
	ft_memset(image->buffer->pixels, 255, sizeof(uint32_t) * image->buffer->width * image->buffer->height);
}