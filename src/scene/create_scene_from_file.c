/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_scene_from_file.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:02:53 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/05 19:54:33 by apaghera         ###   ########.fr       */
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
	char		*str;
	char		*str_buffer[LINEBUFFER_MAX];
	int			width;
	int			height;

	str = *(char **)vector_at(vector, idx);
	if (str && str[idx] == 'R')
	{
		str_buffer[0] = str;
		str = *(char **)vector_at(vector, idx + 1);
		str_buffer[1] = str;
		str = *(char **)vector_at(vector, idx + 2);
		str_buffer[2] = str;
		str_buffer[3] = NULL;
		if (valid_value(str_buffer[1], &ft_isdigit))
		{
			width = ft_atoi(str_buffer[1]);
			height = ft_atoi(str_buffer[2]);
			renderer_initialize(renderer, width, height, true);
			return (1);
		}
		else
			return (0);
	}
	return (0);
}

void	send_to_cam(t_vector *vector, int idx,)

void	create_scene_from_file(t_vector *vector)
{
	t_scene		scene;
	t_renderer	renderer;
	size_t		idx;
	int			flag;

	idx = 0;
	scene = cornell_box();
	flag = 0;
	while (idx < vector->size)
	{
		flag = send_to_res(vector, idx, &renderer);
		idx++;
		break ;
	}
	if (flag)
	{
		scene.camera = camera_new(1920, 1080, 50);
		camera_view_transform(&scene.camera, \
				tuple_new_point(278.0, 278.0, -800), \
				tuple_new_point(278.0, 278.0, 0.0));
		renderer.args.world = &scene;
		mlx_key_hook(renderer.window.mlx, (mlx_keyfunc) key_hooks, &renderer);
		renderer_start_threads(&renderer);
		window_draw_loop(renderer.window.mlx, &renderer);
	}
}
