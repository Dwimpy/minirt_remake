/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:12:54 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/22 11:20:59 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "vector.h"
#include "stdio.h"

void	is_null(char *str, t_vector vector)
{
	if (!str)
		shut_down_parser(vector, "Invalid input");
	else
		return ;
}


void	set_cam_values(char **str, t_vector *vector, t_camera *camera)
{
	int		width;
	int		height;
	int		fov;

	width = 0;
	height = 0;
	fov = 0;
	if (validator(str, &ft_isdigit, 2))
	{
		width = ft_atoi(str[1]);
		height = ft_atoi(str[2]);
		str = *(char ***)vector_at(vector, 1);
		if (str && !ft_strncmp(str[0], "C", 2))
		{
			if (str[4])
				shut_down_parser(*vector, "Invalid camera");
			if (valid_value(str[3], &ft_isdigit))
			{
				fov = ft_atoi(str[3]);
				*camera = camera_new(width, height, fov);
			}
		}
	}
}
