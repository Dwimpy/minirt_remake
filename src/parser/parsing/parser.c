/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:24:57 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/05 15:44:19 by apaghera         ###   ########.fr       */
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

void	divide_values(char *line, t_vector *vector, int fd)
{
	int			i;
	size_t		len;
	t_vector	chars;
	int			write;
	char		*str;

	i = -1;
	chars = vector_init(1, sizeof(char));
	len = ft_strlen(line);
	write = 0;
	while (++i < len)
	{
		if ((line[i] == ' ' || line[i] == '\t' || line[i] == '\n') && write == 0)
			continue ;
		if (!write)
		{
			char c = 'c';
			vector_pushback(&chars, &line[i]);
			if (line[i + 1] == '\n' || line[i + 1] == ' ' || line[i + 1] == '\t' || line[i + 1] == '\0')
				write = 1;
		}
		if (write)
		{
			str = vector_to_string(&chars);
			vector_pushback(vector, &str);
			write = 0;
			vector_clear(&chars);
		}
	}
	vector_free(&chars);
}

t_vector	test_parser(void)
{
	char				*line;
	int					fd;
	t_vector			vector;

	fd = open("src/parser/test_obj.rt", O_RDONLY);
	line = get_next_line(fd);
	vector = vector_init(1, sizeof(char **));
	while (line)
	{
		if (line_is_empty(line))
			divide_values(line, &vector, fd);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (vector);
}
