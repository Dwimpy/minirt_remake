/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:27:54 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/26 13:54:38 by apaghera         ###   ########.fr       */
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

void	add_spp_bpr(t_vector *vector, t_renderer *renderer, \
										char **str, int size)
{
	if (size == 4)
		renderer_set_spp(vector, renderer, ft_atof(str[3]));
	else if (size == 5)
	{
		renderer_set_spp(vector, renderer, ft_atof(str[3]));
		renderer_set_bpr(vector, renderer, ft_atof(str[4]));
	}
}

int	check_res_size(t_vector *vector, char **str)
{
	int	i;

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
	while (str[i][j] && i <= n)
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

int	inspect_ambient_ratio(char **str, int n)
{
	int	i;
	int	j;
	int	dot;

	i = 1;
	j = 0;
	dot = 0;
	while (str[i][j] && i <= n)
	{
		j = 0;
		while (str[i][j])
		{
			if (dot && str[i][j] == '.')
				return (0);
			else if (str[i][j] == '.')
				dot = 1;
			else if (!ft_isdigit(str[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	pass_limit_arg(t_vector *vector, char **str)
{
	if (str[4])
		shut_down_parser(*vector, "Invalid camera");
}
