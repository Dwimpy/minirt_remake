/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_set_window.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:53:38 by arobu             #+#    #+#             */
/*   Updated: 2023/08/22 18:36:57 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "renderer.h"
#include <pthread.h>

void	renderer_initialize(\
	t_renderer *renderer, int32_t width, int32_t height, bool threading)
{
	unsigned int	seed;

	seed = (unsigned int) time(0) ^ (unsigned int) getpid();
	srand(seed);
	renderer->threading = threading;
	renderer->samples_per_pixel = 16.0;
	window_create(&renderer->window, width, height);
	window_add_image(renderer->window.mlx, &renderer->canvas);
	create_tiles(&renderer->tiles, width, height);
	if (renderer->threading)
		pthread_mutex_init(&renderer->mutex, NULL);
	renderer->samples = \
		sample_jittered_new((size_t)renderer->samples_per_pixel);
	cubic_spline_filter(renderer->samples, (size_t)renderer->samples_per_pixel);
	renderer->args.renderer = renderer;
	renderer->exiting = 0;
}