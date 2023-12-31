/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:24:57 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/25 13:24:55 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "vector.h"
#include "stdio.h"
#include "get_next_line.h"

int	line_is_empty(const char *str)
{
	while (str && *str)
		str++;
	if (*str == '\0')
		return (true);
	return (false);
}

void	sort_values(t_vector *vector)
{
	size_t	i;
	char	**tmp;

	i = 0;
	while (i < vector->size)
	{
		tmp = *(char ***)vector_at(vector, i);
		if (!ft_strncmp(tmp[0], "R", 2))
			vector_move_to(vector, i, 0);
		else if (!ft_strncmp(tmp[0], "C", 2))
			vector_move_to(vector, i, 1);
		else if (!ft_strncmp(tmp[0], "L", 2))
			vector_move_to(vector, i, 2);
		else if (!ft_strncmp(tmp[0], "A", 2))
			vector_move_to(vector, i, 3);
		i++;
	}
}

void	replace_spaces(char *str)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] == '\t' || str[i] == '\r' || \
				str[i] == '\v' || str[i] == '\f')
			str[i] = ' ';
		++i;
	}
}

void	parsing_line(t_vector *vector, char *line, int fd)
{
	char	**str;
	char	*trimmed;

	while (line)
	{
		if (line_is_empty(line))
		{
			trimmed = ft_strtrim(line, " \n\t");
			replace_spaces(trimmed);
			if (trimmed[0] != '#')
			{
				str = ft_split(trimmed, ' ');
				if (str && str[0])
					vector_pushback(vector, &str);
				else if (str)
					free(str);
			}
			free(trimmed);
		}
		free(line);
		line = get_next_line(fd);
	}
}

t_vector	parse_file(char *str)
{
	char				*line;
	int					fd;
	t_vector			vector;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Invalid file\n", 13);
		exit(1);
	}
	line = get_next_line(fd);
	vector = vector_init(1, sizeof(char ***));
	parsing_line(&vector, line, fd);
	sort_values(&vector);
	close(fd);
	return (vector);
}
