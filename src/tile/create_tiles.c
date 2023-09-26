/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:28:47 by arobu             #+#    #+#             */
/*   Updated: 2023/09/26 14:59:33 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tile.h"
#include "vector.h"

void	set_tile_settings(t_tile *tile, t_real aspect_ratio)
{
	if (is_approx_equal(\
		aspect_ratio, 1.0, M_EPSILON) || aspect_ratio > 1.0)
	{
		tile->settings.tile_size_x = TILE_SIZE;
		tile->settings.tile_size_y = TILE_SIZE / aspect_ratio;
	}
	else
	{
		tile->settings.tile_size_x = aspect_ratio * TILE_SIZE;
		tile->settings.tile_size_y = TILE_SIZE;
	}
}

size_t	get_tile_dim_height(t_tile *tile, t_tile_params *params)
{
	if (params->height - params->j * tile->settings.tile_size_y >= \
		tile->settings.tile_size_y)
		return (tile->settings.tile_size_y);
	else
		return ((params->height - params->j * \
			tile->settings.tile_size_y) % tile->settings.tile_size_y);
}

size_t	get_tile_dim_width(t_tile *tile, t_tile_params *params)
{
	if (params->width - params->i * tile->settings.tile_size_x >= \
		tile->settings.tile_size_x)
		return (tile->settings.tile_size_x);
	else
		return ((params->width - params->i * \
			tile->settings.tile_size_x) % tile->settings.tile_size_x);
}

void	process_row(t_vector *tiles, ssize_t h, \
	t_tile *tile, t_tile_params *params)
{
			tile->corner.x = params->i * tile->settings.tile_size_x;
			tile->corner.y = params->j * tile->settings.tile_size_y;
			tile->dim.height = h;
			tile->dim.w = get_tile_dim_width(tile, params);
}

void	create_tiles(t_vector *tiles, int32_t width, int32_t height)
{
	t_tile			tile;
	size_t			tile_dim_height;
	t_tile_params	params;
	t_vector		tiless;
	initialize_params(&params, &tile, width, height);
	*tiles = vector_init(params.width / tile.settings.tile_size_x * \
		params.height / tile.settings.tile_size_y, sizeof(t_tile));
	tiless = vector_init(10, sizeof(t_tile));
	printf("This: %zu\t", tiles->size);
	printf("%zu\t", tiless.size);
	while (params.j * tile.settings.tile_size_y < (size_t)(height - 1))
	{
		params.i = 0;
		tile_dim_height = get_tile_dim_height(&tile, &params);
//		printf("Height: %zu\tTiles x: %zu\tTiles y: %zu\t", tile_dim_height, params.width / tile.settings.tile_size_x, params.height / tile.settings.tile_size_y);
		while (params.i * tile.settings.tile_size_x < (size_t)(width - 1))
		{
//			printf("HELLO");
			process_row(tiles, tile_dim_height, &tile, &params);
			params.i++;
//			printf("%zu\n", tile.dim.w);
//			printf("%zu\n", tiles->size);
			vector_pushback(tiles, &tile);
//			printf("%zu", (width - params.i * tile.settings.tile_size_x));
			if ((width - params.i * tile.settings.tile_size_x) <= 0)
				break ;
		}
		params.j++;
		if ((height - params.j * tile.settings.tile_size_y) <= 0)
			break ;
	}
}
