/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_initialize.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:53:38 by arobu             #+#    #+#             */
/*   Updated: 2023/09/25 15:05:14 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "renderer.h"
#include "parser.h"
#include <pthread.h>

int	power_of_two(unsigned int i)
{
	unsigned int	power;

	power = 1;
	while (power <= i)
	{
		if (power == i)
			return (1);
		power *= 2;
	}
	return (0);
}

void	renderer_initialize(\
	t_renderer *renderer, int32_t width, int32_t height, bool threading)
{
	unsigned int	seed;

	seed = (unsigned int) time(0) ^ (unsigned int) getpid();
	srand(seed);
	renderer->threading = threading;
	window_create(&renderer->window, width, height);
	window_add_image(renderer->window.mlx, &renderer->canvas);
	create_tiles(&renderer->tiles, width, height);
	renderer->samples_per_pixel = 32;
	renderer->bounces_per_ray = 10;
	if (renderer->threading)
		pthread_mutex_init(&renderer->mutex, NULL);
	renderer->samples = \
		sample_jittered_new((size_t)renderer->samples_per_pixel);
	cubic_spline_filter(renderer->samples, (size_t)renderer->samples_per_pixel);
	renderer->args.renderer = renderer;
	renderer->exiting = 0;
}

void	renderer_set_spp(t_vector *vector, t_renderer *renderer, size_t spp)
{
	if (power_of_two(spp) && spp > 0)
		renderer->samples_per_pixel = spp;
	else
		shut_down_parser(*vector, "Value is not a power of 2");
}

void	renderer_set_bpr(t_vector *vector, t_renderer *renderer, size_t bpr)
{
	if (bpr > 0)
		renderer->bounces_per_ray = bpr;
	else
		shut_down_parser(*vector, "Invalid bounces");
}
