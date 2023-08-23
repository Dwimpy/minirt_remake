/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:23:19 by arobu             #+#    #+#             */
/*   Updated: 2023/07/31 16:23:19 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "unistd.h"
#include <stdlib.h>

void	window_create(t_window *window, int32_t width, int32_t height)
{
	window->width = width;
	window->height = height;
	window->mlx = mlx_init(width, height, "MiniRT", false);
	if (!window->mlx)
	{
		write(2, WINDOW_MLX_ALLOC_FAILED, 38);
		exit(EXIT_FAILURE);
	}
}
