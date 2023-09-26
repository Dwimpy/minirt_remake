/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_scene_from_file.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:02:53 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/26 10:48:36 by apaghera         ###   ########.fr       */
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

int validator(char **str, int (*comparator)(int c), int n) {
	int i;

	i = 1;
	while (i <= n) {
		if (!valid_value(str[i], comparator))
			return (false);
		i++;
	}
	return (true);
}

int validator_special(char **str, int (*comparator)(int c), int n)
{
	int i;

	i = 0;
	while (i <= n) {
		if (!valid_value(str[i], comparator))
			return (false);
		i++;
	}
	return (true);
}

void add_spp_bpr(t_vector *vector, t_renderer *renderer, \
                                        char **str, int size) {
	if (size == 4)
		renderer_set_spp(vector, renderer, ft_atof(str[3]));
	else if (size == 5) {
		renderer_set_spp(vector, renderer, ft_atof(str[3]));
		renderer_set_bpr(vector, renderer, ft_atof(str[4]));
	}
}

int check_res_size(t_vector *vector, char **str) {
	int i;

	i = 0;
	while (str[i])
		i++;
	if (i > 5)
		shut_down_parser(*vector, "Too many arg in resolution");
	return (i);
}

int	inspect_res_value(char **str, int n)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (str[i][j] && i < n)
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void send_to_res(t_vector *vector, t_renderer *renderer) {
	char **str;
	int width;
	int height;
	int size;

	str = *(char ***) vector_at(vector, 0);
	size = check_res_size(vector, str);
	if (!inspect_res_value(str, 2))
		shut_down_parser(*vector, "Resolution is not a digit");
	if (str && !ft_strncmp(str[0], "R", 2))
	{
		if (validator(str, &ft_isdigit, 2))
		{
			width = ft_atoi(str[1]);
			height = ft_atoi(str[2]);
			renderer_initialize(renderer, width, height, true);
			add_spp_bpr(vector, renderer, str, size);
		} else
			shut_down_parser(*vector, "Invalid Input");
	} else
		shut_down_parser(*vector, "Invalid resolution");
}

void send_to_cam(t_vector *vector, t_camera *camera) {
	char **str;

	str = *(char ***) vector_at(vector, 0);
	if (str && !ft_strncmp(str[0], "R", 2))
		set_cam_values(str, vector, camera);
	else
		shut_down_parser(*vector, "Invalid value cam");
}

t_scene scene_from_file(t_renderer *renderer, char *filepath) {
	t_scene scene;
	t_vector parsed_data;


	parsed_data = parse_file(filepath);
	if (!check_parsed_data(&parsed_data))
		shut_down_parser(parsed_data, "Error parsing");
	scene = scene_give_light(&parsed_data);
	scene_object_maker(parsed_data, &scene);
	send_to_res(&parsed_data, renderer);
	send_to_cam(&parsed_data, &scene.camera);
	camera_view_transform(&scene.camera, \
        parse_vector(&parsed_data, 1, 1, "none"), \
            parse_vector(&parsed_data, 1, 2, "none"));
	free_parser(parsed_data);
	return (scene);
}
