/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:34:34 by arobu             #+#    #+#             */
/*   Updated: 2023/08/22 21:35:40 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

void	key_hooks(mlx_key_data_t key_data, void *param)
{
	t_renderer	*renderer;

	renderer = param;
	if (key_data.key == MLX_KEY_ESCAPE)
		mlx_close_window(renderer->window.mlx);
}