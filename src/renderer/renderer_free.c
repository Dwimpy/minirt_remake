/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:40:26 by arobu             #+#    #+#             */
/*   Updated: 2023/09/22 15:15:01 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

void	renderer_free(t_renderer *renderer)
{
	vector_free(&renderer->tiles);
	free(renderer->samples);
}
