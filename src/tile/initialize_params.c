/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_params.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:01:17 by arobu             #+#    #+#             */
/*   Updated: 2023/09/26 15:01:17 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tile.h"

void	initialize_params(t_tile_params *params, \
	t_tile *tile, int32_t w, int32_t h)
{
	params->j = 0;
	params->width = w;
	params->height = h;
	params->aspect_ratio = (t_real)w / (t_real)h;
	set_tile_settings(tile, params->aspect_ratio);
}
