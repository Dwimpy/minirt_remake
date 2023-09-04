/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_scene_from_file.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:02:53 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/04 16:18:17 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "vector.h"
#include "hooks.h"
#include "parser.h"
#include "libft.h"
#include <stdio.h>

void	get_value_file(t_vector *vector)
{

}

void	create_scene_from_file(t_vector *vector)
{
	t_scene		scene;
	t_renderer	renderer;
	double		find;
	size_t		idx;

	find = 800;
	idx = vector_binary_search(vector, find);
	printf("IDX: [%zu] WORD: [%s] \n", idx, *(char **)vector_at(vector, 1));
	renderer_initialize(&renderer, ft_atoi(*(char **)vector_at(vector, 1)), ft_atoi(*(char **)vector_at(vector, 2)), true);
	scene = cornell_box();
	scene.camera = camera_new(1920, 1080, 50);
	camera_view_transform(&scene.camera, \
			tuple_new_point(278.0, 278.0, -800), \
			tuple_new_point(278.0, 278.0, 0.0));
	renderer.args.world = &scene;
	mlx_key_hook(renderer.window.mlx, (mlx_keyfunc) key_hooks, &renderer);
	renderer_start_threads(&renderer);
	window_draw_loop(renderer.window.mlx, &renderer);
}
