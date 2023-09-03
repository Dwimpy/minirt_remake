/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:24:57 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/03 23:03:12 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "vector.h"
#include "stdio.h"
#include "get_next_line.h"

int	min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

void	*one_space(char *line)
{
	int		i;
	char	buffer[LINEBUFFER_MAX];
	int		j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == 32)
		{
			buffer[j] = 32;
			j++;
			while (line[i] == 32)
			{
				i++;
				if (!line && !line[i])
					break ;
			}
		}
		if (line[i] == '\n')
			break ;
		buffer[j] = line[i];
		j++;
		i++;
	}
	buffer[j] = '\0';
	return (ft_strdup(buffer));
}

int		line_is_empty(const char *str)
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
			vector_pushback(&chars, &line[i]);
			if (line[i + 1] == '\n' || line[i + 1] == ' ' || line[i + 1] == '\t' || line[i + 1] == '\0')
				write = 1;
		}
		if (write)
		{
			char	*str;
			str = vector_to_string(&chars);
			vector_pushback(vector, &str);
			write = 0;
			vector_clear(&chars);
		}
	}
	vector_free(&chars);
}

void	test_parser(void)
{
	char		*line;
	int			fd;
	char		*tmp;
	t_vector	vector;

	fd = open("src/parser/test_obj.rt", O_RDONLY);
	line = get_next_line(fd);
	vector = vector_init(5, sizeof(char **));
	printf("Vector Item Size: %zu\n", vector.item_size);
	while (line)
	{
		if (line_is_empty(line))
			divide_values(line, &vector, fd);
		free(line);
		line = get_next_line(fd);
	}
	t_vector_iterator it;
	vector_iterator_begin(&it, &vector);
	for (int i = 0; i < vector.size; ++i)
	{
		printf("%s\n", *(char **)vector_at(&vector, i));
	}
//	printf("Size: %zu\n", vector.size);
	close(fd);
}
