/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_give_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:09:58 by arobu             #+#    #+#             */
/*   Updated: 2023/09/22 15:14:39 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "parser.h"

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

t_scene	scene_give_light(t_vector *vector)
{
	t_scene	world;
	t_tuple	color;
	char	**str;

	str = *(char ***)vector_at(vector, 3);
	if (str[3])
		shut_down_parser(*vector, "Invalid ambient");
	color = parse_vector(vector, 2, 3);
	str = *(char ***)vector_at(vector, 2);
	if (str[4])
		shut_down_parser(*vector, "Invalid light");
	world.light = light_rect_new((t_rect_light_params)
	{
		parse_vector(vector, 2, 1),  // from
		color_multiply_s(color, (1.0 / 255.0)),  //rgb + ratio
		tuple_new_point(0, 1, 0),
		coord_new(32, 32), 2 // size of rectangle "quality of light"
	}); // i need only this for the light create a new function
//	world.light = light_point_new(tuple_new_point(0, 25, -120), color_new(0.2, 0.2, 0.2));
	world.objs = vector_init(10, sizeof(t_shape));
	world.comps.ref_index_tracker = vector_init(10, sizeof(t_shape **));
	return (world);
}