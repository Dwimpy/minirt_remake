/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_scene_from_file.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:02:53 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/06 16:16:22 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "vector.h"
#include "hooks.h"
#include "parser.h"
#include "libft.h"
#include "sphere.h"
#include <stdio.h>

int	valid_value(char *str, int (*comparator)(int c))
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (!comparator(str[i]))
			return (false);
		i++;
	}
	return (true);
}

int	send_to_res(t_vector *vector, int idx, t_renderer *renderer)
{
	char		**str;
	int			width;
	int			height;

	str = *(char ***)vector_at(vector, idx);
	if (str && !ft_strncmp(str[idx], "R", 2))
	{
		if (valid_value(str[1], &ft_isdigit))
		{
			width = ft_atoi(str[1]);
			height = ft_atoi(str[2]);
			return (1);
		}
		else
			return (0);
	}
	return (0);
}

void	send_to_cam(t_vector *vector, int idx)
{
	
}

void	create_scene_from_file(t_vector *vector)
{
	t_scene		scene;
	t_renderer	renderer;
	size_t		idx;
	int			flag;
	char		**str;

	idx = 0;
	scene = cornell_box();
	flag = 0;

	while (idx < vector->size)
	{
		str = *(char ***)vector_at(vector, idx);
		if (send_to_res(vector, idx, &renderer))
		{
			renderer_initialize(&renderer, 800, 600, true);
			scene.camera = camera_new(800, 600, 80);
			camera_view_transform(&scene.camera, \
					tuple_new_point(278.0, 278.0, -800), \
					tuple_new_point(278.0, 278.0, 0.0));
			renderer.args.world = &scene;
		}
		idx++;
		break ;
	}
	mlx_key_hook(renderer.window.mlx, (mlx_keyfunc) key_hooks, &renderer);
	renderer_start_threads(&renderer);
	window_draw_loop(renderer.window.mlx, &renderer);
}
