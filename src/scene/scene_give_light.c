/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_give_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:09:58 by arobu             #+#    #+#             */
/*   Updated: 2023/09/24 15:36:06 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "parser.h"

int	valid_value(char *str, int (*comparator)(int c))
{
	size_t	i;
	size_t	len;
	int		isdot;

	i = 0;
	isdot = 0;
	if (!str)
	{
		write(2, "\x1b[31m", 6);
		write(2, "Invalid input\n", 14);
		exit(0);
	}
	len = ft_strlen(str);
	while (i < len)
	{
		if (isdot == 1 && str[i] == '.')
			return false;
		else if (str[i] == '.')
			isdot = 1;
		else if (!comparator(str[i]))
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
	printf("%s\n", str[1]);
	if (str[1] && (ft_atof(str[1]) > 1.0 || ft_atof(str[1]) < 0.0))
		shut_down_parser(*vector, "Ambient out of ratio");
	color = parse_vector(vector, 2, 3, "colour");
	str = *(char ***)vector_at(vector, 2);
	if (str[4])
		shut_down_parser(*vector, "Invalid light");
	world.light = light_rect_new((t_rect_light_params)
		{
			parse_vector(vector, 2, 1, "none"),
			color_multiply_s(color, (1.0 / 255.0)),
			tuple_new_point(0, 1, 0),
			coord_new(32, 32), 2
		});
	world.objs = vector_init(10, sizeof(t_shape));
	world.comps.ref_index_tracker = vector_init(10, sizeof(t_shape **));
	return (world);
}
