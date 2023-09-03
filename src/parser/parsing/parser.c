/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:24:57 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/03 21:31:34 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "vector.h"
#include "stdio.h"

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
	{
		if (*str != ' ' || *str != '\t' || *str != '\n')
			return (false);
		str++;
	}
	return (true);
}

void	divide_values(char *line, t_vector *vector, int fd)
{
	int			i;
	size_t		len;
	t_vector	chars;
	int			wasSpace;

	i = 0;
	
	chars = vector_init(1, sizeof(char));
	len = ft_strlen(line);
	wasSpace = 0;
	while (i < len)
	{
		
		if (line[i] == '\0')
			break ;
		else if (line[i] == 32)
		{
			char *str;
			str = vector_to_string(&chars);
			printf("STR: %s\n", str);
			vector_pushback(vector, str);
			vector_clear(&chars);
			while (line[i] == 32 || line[i] == '\t' || line[i] == '\n')
				i++;
			i--;
		}
		else if (line[i] != 32 && line[i] != '\0')
		{
			vector_pushback(&chars, &line[i]);
			// printf("%c", line[i]);
		}
		i++;
	}
	vector_pushback(vector, vector_to_string(&chars));
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
	vector = vector_init(10, sizeof(char *));
	while (line)
	{
		if (!line_is_empty(line))
			divide_values(line, &vector, fd);
		free(line);
		line = get_next_line(fd);
	}
	t_vector_iterator it;
	vector_iterator_begin(&it, &vector);
	while (!it.end(&it))
	{
		char *str = it.get(&it);
		printf("%s\n", (char *)vector_back(&vector));
		it.next(&it);
	}
	close(fd);
}
