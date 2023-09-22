/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:05:08 by arobu             #+#    #+#             */
/*   Updated: 2023/08/23 13:05:35 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H
# define NUM_THREADS 200
# include "tile.h"
# include "window.h"
# include "sampling.h"

typedef struct s_renderer
{
	t_window		window;
	t_image			canvas;
	t_vector		tiles;
	t_thread_args	args;
	t_sample		*samples;
	pthread_t		threads[NUM_THREADS];
	pthread_mutex_t	mutex;
	t_real			samples_per_pixel;
	bool			exiting;
	bool			threading;
}				t_renderer;

void	renderer_initialize(\
		t_renderer *renderer, \
		int32_t width, \
		int32_t height, \
		bool threading);
void	renderer_start_threads(t_renderer *renderer);
void	renderer_free(t_renderer *renderer);
#endif
