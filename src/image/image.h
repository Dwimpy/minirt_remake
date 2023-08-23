/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:37:11 by arobu             #+#    #+#             */
/*   Updated: 2023/08/23 13:15:38 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H
# define IMAGE_BUFFER_ALLOC_FAILED\
	"MLX Image buffer allocation failed. Exiting."
# include "MLX42.h"
# include <stdint.h>
# include "color.h"

typedef struct s_image
{
	mlx_image_t	*buffer;
	uint32_t	width;
	uint32_t	height;
}				t_image;

void	image_create(\
	mlx_t *mlx, t_image *image, uint32_t width, uint32_t height);
void	image_set_pixel(t_image *image, t_color c, uint32_t u, uint32_t v);
#endif