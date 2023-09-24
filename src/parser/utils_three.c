/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:12:54 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/24 15:26:04 by apaghera         ###   ########.fr       */
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
				if (fov < 5.0 || fov > 180.0)
					shut_down_parser(*vector, "Invalid fov");
				*camera = camera_new(width, height, fov);
			}
		}
	}
}

int	check_out_range(char *token, int first, int second, int third)
{

	if (!ft_strncmp(token, "rotate", 7))
	{
		if ((first < -180.0 || first > 180.0) || \
			(second < -180.00 || second > 180.0) || \
			(third < -180.0 || third > 180.0))
			return (1);
	}
	else if (!ft_strncmp(token, "colour", 7))
	{
		if ((first < 0.0 || first > 255.0) || \
			(second < 0.0 || second > 255.0) || \
			(third < 0.0 || third > 255.0))
		{
			return (1);
		}
	}
	else if (!ft_strncmp(token, "none", 5))
		return (0);
	return (0);
}
