/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_draw_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:34:04 by arobu             #+#    #+#             */
/*   Updated: 2023/07/31 16:34:04 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

void	window_draw_loop(mlx_t *mlx, t_renderer *renderer)
{
	int	i;

	i = -1;
	mlx_loop(mlx);
	pthread_mutex_lock(&renderer->mutex);
	renderer->exiting = 1;
	pthread_mutex_unlock(&renderer->mutex);
	while (++i < NUM_THREADS)
		pthread_join(renderer->threads[i], NULL);
	mlx_terminate(mlx);
}
