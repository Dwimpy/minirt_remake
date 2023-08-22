/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:28:47 by arobu             #+#    #+#             */
/*   Updated: 2023/08/22 17:05:24 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tile.h"
#include "vector.h"

void	create_tiles(t_vector *tiles, int32_t width, int32_t height)
{
	t_tile		tile;
	size_t		i;
	size_t		j;
	size_t		tile_dim_height;
	t_real		aspect_ratio;

	j = 0;
	aspect_ratio = (t_real)width / (t_real)height;
	if (is_approx_equal(\
		aspect_ratio, 1.0, M_EPSILON) || aspect_ratio > 1.0)
	{
		tile.settings.tile_size_x = TILE_SIZE;
		tile.settings.tile_size_y = TILE_SIZE / aspect_ratio;
	}
	else
	{
		tile.settings.tile_size_x = aspect_ratio * TILE_SIZE;
		tile.settings.tile_size_y = TILE_SIZE;
	}
	*tiles = vector_init(width / tile.settings.tile_size_x * height / tile.settings.tile_size_y, sizeof(t_tile));
	while (j * tile.settings.tile_size_y < (height - 1))
	{
		i = 0;
		tile_dim_height = ((height - j * tile.settings.tile_size_y) >= tile.settings.tile_size_y) ? tile.settings.tile_size_y : (height - j * tile.settings.tile_size_y) % tile.settings.tile_size_y;
		while (i * tile.settings.tile_size_x < width)
		{
			tile.corner.x = i * tile.settings.tile_size_x;
			tile.corner.y = j * tile.settings.tile_size_y;
			tile.dim.w = ((width - i * tile.settings.tile_size_x) >= tile.settings.tile_size_x) ? tile.settings.tile_size_x : (width - i * tile.settings.tile_size_x) % tile.settings.tile_size_x;
			tile.dim.height = tile_dim_height;
			i++;
			vector_pushback(tiles, &tile);
			if ((width - i * tile.settings.tile_size_x) == 0)
				break ;
		}
		j++;
		if ((height - j * tile.settings.tile_size_y) == 0)
			break ;
	}
}
