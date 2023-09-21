/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:27:37 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/21 11:31:20 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser/parser.h"
#include "libft.h"
#include "vector.h"
#include "stdio.h"
#include "material.h"

t_material_result	def_material(char **str, t_color color, \
									int column, t_material *material)
{
	if (str && str[column])
	{
		if (!ft_strncmp(str[column], "copper", 7))
		{
			*material = material_copper();
			return (MATERIAL_SUCCESS);
		}
		else if (!ft_strncmp(str[column], "glass", 6))
		{
			*material = material_glass(color);
			return (MATERIAL_SUCCESS);
		}
		else if (!ft_strncmp(str[column], "lambertian", 10))
		{
			*material = material_lambertian(color_multiply_s \
						(color, (1.0 / 255.0)));
			return (MATERIAL_SUCCESS);
		}
		return (INVALID_TYPE);
	}
	return (INVALID_INPUT);
}

void	free_double_arr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i])
			free(str[i]);
		i++;
	}
	if (str)
		free(str);
}

void	print_str(char *str)
{
	int	i;

	i = 0;
	write(2, "\x1b[31m", 6);
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	write(2, "\n", 1);
}

void	shut_down_parser(t_vector vector, char *str)
{
	print_str(str);
	free_parser(vector);
	exit(1);
}
