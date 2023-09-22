/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_scene_from_file.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:02:53 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/22 11:21:18 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "vector.h"
#include "hooks.h"
#include "parser.h"
#include "libft.h"
#include "sphere.h"
#include "cylinder.h"
#include <stdio.h>

int	valid_value(char *str, int (*comparator)(int c))
{
	size_t	i;
	size_t	len;

	i = 0;
	if (!str)
	{
		write(2, "\x1b[31m", 6);
		write(2, "Invalid input\n", 14);
		exit(0);
	}
	len = ft_strlen(str);
	while (i < len)
	{
		if (!comparator(str[i]))
			return (false);
		i++;
	}
	return (true);
}

int	validator(char **str, int (*comparator)(int c), int n)
{
	int	i;

	i = 1;
	while (i <= n)
	{
		if (!valid_value(str[i], comparator))
			return (false);
		i++;
	}
	return (true);
}

void	send_to_res(t_vector *vector, t_renderer *renderer)
{
	char		**str;
	int			width;
	int			height;

	str = *(char ***)vector_at(vector, 0);
	if (str[3])
		shut_down_parser(*vector, "Invalid resolution");
	if (str && !ft_strncmp(str[0], "R", 2))
	{
		if (validator(str, &ft_isdigit, 2))
		{
			width = ft_atoi(str[1]);
			height = ft_atoi(str[2]);
			renderer_initialize(renderer, width, height, true);
		}
	}
	else
		shut_down_parser(*vector, "Invalid resolution");
}

void	send_to_cam(t_vector *vector, t_camera *camera)
{
	char	**str;
	int		width;
	int		height;
	int		fov;

	str = *(char ***)vector_at(vector, 0);
	if (str && !ft_strncmp(str[0], "R", 2))
		set_cam_values(str, vector, camera);
	else
		shut_down_parser(*vector, "Invalid value cam");
}

void	create_scene_from_file(t_vector *vector, t_scene *scene)
{
	t_renderer	renderer;

	send_to_res(vector, &renderer);
	send_to_cam(vector, &scene->camera);
	camera_view_transform(&scene->camera, \
		parse_vector(vector, 1, 1), \
			parse_vector(vector, 1, 2));
	renderer.args.world = scene;
	mlx_key_hook(renderer.window.mlx, (mlx_keyfunc) key_hooks, &renderer);
	renderer_start_threads(&renderer);
	window_draw_loop(renderer.window.mlx, &renderer);
}
