/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:16:46 by arobu             #+#    #+#             */
/*   Updated: 2023/09/05 15:29:52 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TILE_H
# define TILE_H
# include "camera.h"
# include "image.h"
# include "ray.h"
# include "vector.h"
// # include <sys/_types/_size_t.h>
# include "tuple.h"
# include "scene.h"

# define TILE_SIZE 100

typedef struct s_renderer	t_renderer;

typedef struct s_tile_settings
{
	size_t		tile_size_x;
	size_t		tile_size_y;
}				t_tile_settings;

typedef struct s_tile_corner
{
	size_t		x;
	size_t		y;
}				t_tile_corner;

typedef struct s_tile_size
{
	size_t		w;
	size_t		height;
}				t_tile_size;

typedef struct s_tile
{
	t_tile_corner	corner;
	t_tile_size		dim;
	t_tile_settings	settings;
}				t_tile;

typedef struct s_thread_args
{
	t_scene		*world;
	t_renderer	*renderer;
}				t_thread_args;

typedef struct s_tile_params
{
	int32_t		width;
	int32_t		height;
	size_t		i;
	size_t		j;
	t_real		aspect_ratio;
}				t_tile_params;

typedef struct s_thread_params
{
	t_ray		ray;
	size_t		i;
	size_t		j;
	size_t		k;
	t_tile		*tile;
	t_color		color;
}				t_thread_params;

void		create_tiles(t_vector *tiles, int32_t width, int32_t height);
void		*render_tiles(void *arg);
void		set_tile_settings(t_tile *tile, t_real aspect_ratio);
void		initialize_params(t_tile_params *params, \
	t_tile *tile, int32_t w, int32_t h);
void		render_tile(t_thread_args *args);
#endif