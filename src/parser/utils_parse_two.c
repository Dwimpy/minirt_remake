/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:02:06 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/25 09:55:50 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "vector.h"
#include "stdio.h"

t_tuple	parse_vector(t_vector *vector, int idx, \
						int column, char *token)
{
	char	**str;
	char	**values;
	t_tuple	point;

	str = *(char ***)vector_at(vector, idx);
	point = tuple_point_zero();
	if (str && view_from_to_valid(str[column], *vector))
	{
		values = ft_split(str[column], ',');
		if (check_out_range(token, ft_atof(values[0]), ft_atof(values[1]), \
														ft_atof(values[2])))
			shut_down_parser(*vector, "Values out of scope");
		point = tuple_new_point(ft_atof(values[0]), ft_atof(values[1]), \
													ft_atof(values[2]));
		free_double_arr(values);
	}
	else
		shut_down_parser(*vector, "Invalid input");
	return (point);
}

int	positive_negative(char *str, t_vector vector, int i)
{
	if (str[i] == '-' || str[i] == '+')
	{
		if (ft_isdigit(str[i + 1]))
			return (1);
		else
			shut_down_parser(vector, "Invalid input");
	}
	return (0);
}

int	has_coma(char *str, int i, int *dot, int *count)
{
	if (str[i] == ',')
	{
		*dot = 0;
		*count += 1;
		return (1);
	}
	return (0);
}

void	has_dot(char *str, t_vector vector, int *i, int *dot)
{
	if (*dot)
		shut_down_parser(vector, "Invalid input");
	*dot = 1;
	if (str[*(i) + 1] == '.')
		shut_down_parser(vector, "Invalid input");
	*i += 1;
}

int	view_from_to_valid(char *str, t_vector vector)
{
	int	i;
	int	count;
	int	dot;

	i = 0;
	count = 0;
	dot = 0;
	how_many_values(str, vector);
	while (str[i])
	{
		if (str[i] && ft_isdigit(str[i]))
			i++;
		else if (positive_negative(str, vector, i))
			i++;
		else if (has_coma(str, i, &dot, &count))
			i++;
		else if (str[i] == '.')
			has_dot(str, vector, &i, &dot);
		else
			shut_down_parser(vector, "Invalid input");
	}
	if (count == 2)
		return (1);
	shut_down_parser(vector, "Invalid input");
	return (0);
}
