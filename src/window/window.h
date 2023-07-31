/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:18:36 by arobu             #+#    #+#             */
/*   Updated: 2023/07/31 16:18:36 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H
# define WINDOW_MLX_ALLOC_FAILED "MLX window allocation failed. Exiting."

# include "MLX42.h"
# include "image.h"
# include <stdint.h>

typedef struct s_window
{
	mlx_t		*mlx;
	int32_t		width;
	int32_t		height;
}				t_window;

void	window_create(t_window *window, int32_t width, int32_t height);
void	window_add_image(mlx_t *window, t_image *image);
void	window_draw_loop(mlx_t *mlx);

#endif