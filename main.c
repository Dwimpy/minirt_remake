/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:06:16 by arobu             #+#    #+#             */
/*   Updated: 2023/09/25 13:44:24 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "hooks.h"
#include "libft.h"
#include "parser.h"

void	leaks(void)
{
	system("leaks miniRT");
}

int	main(int argc, char **argv)
{
	t_scene		scene;
	t_renderer	renderer;

	if (!is_input_ok(argc, argv))
		exit(EXIT_FAILURE);
	scene = scene_from_file(&renderer, argv[1]);
	mlx_key_hook(renderer.window.mlx, (mlx_keyfunc) key_hooks, &renderer);
	renderer.args.world = &scene;
	renderer_start_threads(&renderer);
	window_draw_loop(renderer.window.mlx, &renderer);
	renderer_free(&renderer);
	scene_free(&scene);
	return (0);
}
