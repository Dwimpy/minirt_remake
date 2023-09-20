/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:27:37 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/20 11:19:21 by apaghera         ###   ########.fr       */
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
		if (!ft_strncmp(str[column], "copper", ft_strlen("copper")))
		{
			*material = material_copper();
			return (MATERIAL_SUCCESS);
		}
		else if (!ft_strncmp(str[column], "glass", ft_strlen("glass")))
		{
			*material = material_glass(color);
			return (MATERIAL_SUCCESS);
		}
		else if (!ft_strncmp(str[column], "lambert", ft_strlen("lambert")))
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
