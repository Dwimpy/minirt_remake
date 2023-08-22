/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tiles_thread.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:58:53 by arobu             #+#    #+#             */
/*   Updated: 2023/08/22 21:59:09 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

void	*render_tiles(void *arg)
{
	t_thread_args	*thread_args;
	size_t			i;

	thread_args = (t_thread_args *)arg;
	i = 0;
	while (i < NUM_THREADS)
	{
		render_tile(thread_args);
		i++;
	}
	return (NULL);
}
