/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_start_threads.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:43:08 by arobu             #+#    #+#             */
/*   Updated: 2023/08/22 18:04:47 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include <pthread.h>

void	renderer_start_threads(t_renderer *renderer)
{
	size_t	i;

	i = 0;
	while (i < NUM_THREADS)
	{
		pthread_create(\
			&renderer->threads[i], NULL, render_tiles, &renderer->args);
		++i;
	}
}
