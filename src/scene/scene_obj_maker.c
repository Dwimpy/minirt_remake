/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_obj_maker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:15:28 by arobu             #+#    #+#             */
/*   Updated: 2023/09/24 15:29:38 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "parser.h"
#include "cube.h"
#include "cylinder.h"
#include "plane.h"


static int	mandatory_identifier(char *str)
{
	if (!ft_strncmp(str, "#", 2))
		return (1);
	else if (!ft_strncmp(str, "R", 2))
		return (1);
	else if (!ft_strncmp(str, "L", 2))
		return (1);
	else if (!ft_strncmp(str, "A", 2))
		return (1);
	else if (!ft_strncmp(str, "C", 2))
		return (1);
	else
		return (0);
}

void	scene_object_maker(t_vector vector, t_scene *scene)
{
	size_t	i;
	char	**str;

	i = 0;
	while (i < vector.size)
	{
		str = *(char ***)vector_at(&vector, i);
		if (!ft_strncmp(str[0], "sp", 3))
			create_sphere(vector, scene, i);
		else if (!ft_strncmp(str[0], "cu", 3))
			create_cube(vector, scene, i);
		else if (!ft_strncmp(str[0], "cy", 3))
			create_cylinder(vector, scene, i);
		else if (!ft_strncmp(str[0], "pl", 3))
			create_plane(vector, scene, i);
		else
		{
			if (!mandatory_identifier(str[0]))
				shut_down_parser(vector, "Identifier not found");
		}
		i++;
	}
}
