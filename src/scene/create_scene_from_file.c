/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_scene_from_file.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:02:53 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/10 17:38:25 by apaghera         ###   ########.fr       */
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
	if (str && !ft_strncmp(str[0], "R", 2))
	{
		if (validator(str, &ft_isdigit, 2))
		{
			width = ft_atoi(str[1]);
			height = ft_atoi(str[2]);
			renderer_initialize(renderer, width, height, true);
		}
	}
}

void	send_to_cam(t_vector *vector, t_camera *camera)
{
	char	**str;
	int		width;
	int		height;
	int		fov;

	str = *(char ***)vector_at(vector, 0);
	if (str && !ft_strncmp(str[0], "R", 2))
	{
		if (validator(str, &ft_isdigit, 2))
		{
			width = ft_atoi(str[1]);
			height = ft_atoi(str[2]);
			str = *(char ***)vector_at(vector, 1);
			if (str && !ft_strncmp(str[0], "C", 2))
			{
				if (valid_value(str[3], &ft_isdigit))
				{
					fov = ft_atoi(str[3]);
					*camera = camera_new(width, height, fov);
				}
			}
		}
	}
}

int	view_from_to_valid(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else if (str[i] == '-' || str[i] == '+')
		{
			if (ft_isdigit(str[i + 1]))
				i++;
			else
				return (0);
		}
		else if (str[i] == ',')
		{
			count++;
			i++;
		}
		else if (str[i] == '.')
			i++;
		else
			return (0);
	}
	if (count == 2)
		return (1);
	return (0);
}

t_tuple parse_vector(t_vector *vector, int idx, int column)
{
	char	**str;
	char	**values;
	t_tuple	point;

	str = *(char ***)vector_at(vector, idx);
	if (view_from_to_valid(str[column]))
	{
		values = ft_split(str[column], ',');
		point = tuple_new_point(ft_atof(values[0]), ft_atof(values[1]), \
													ft_atof(values[2]));
	}
	free(values);
	return (point);
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
