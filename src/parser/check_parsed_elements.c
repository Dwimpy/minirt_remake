/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsed_elements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:39:28 by arobu             #+#    #+#             */
/*   Updated: 2023/09/22 15:39:28 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int check_mandatory_elements(t_vector *vector)
{
	char	**str;
	size_t	i;

	i = 0;
	while (i < 4)
	{
		str = *(char ***)vector_at(vector, i);
		if (ft_strncmp(str[0], "R", 2) && ft_strncmp(str[0], "C", 2) && ft_strncmp(str[0], "A", 2) && ft_strncmp(str[0], "L", 2))
			return (0);
		i++;
	}
	return (1);
}

int	check_parsed_data(t_vector *parsed_data)
{
	if (parsed_data->size < 4)
		return (0);
	return (check_mandatory_elements(parsed_data));
}