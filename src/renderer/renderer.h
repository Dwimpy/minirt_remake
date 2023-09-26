/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:05:08 by arobu             #+#    #+#             */
/*   Updated: 2023/09/25 15:04:09 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H
# define NUM_THREADS 50
# include "tile.h"
# include "window.h"
# include "sampling.h"
# include "vector.h"

typedef struct s_renderer
{
	t_window		window;
	t_image			canvas;
	t_vector		tiles;
	t_thread_args	args;
	t_sample		*samples;
	pthread_t		threads[NUM_THREADS];
	pthread_mutex_t	mutex;
	size_t			samples_per_pixel;
	size_t			bounces_per_ray;
	bool			exiting;
	bool			threading;
}				t_renderer;

void	renderer_initialize(\
		t_renderer *renderer, \
		int32_t width, \
		int32_t height, \
		bool threading);
void	renderer_start_threads(t_renderer *renderer);
void	renderer_set_spp(t_vector *vector, t_renderer *renderer, size_t spp);
void	renderer_set_bpr(t_vector *vector, t_renderer *renderer, size_t bpr);
void	renderer_free(t_renderer *renderer);

#endif
