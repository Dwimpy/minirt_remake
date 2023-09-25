/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_ok.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:01:14 by arobu             #+#    #+#             */
/*   Updated: 2023/09/25 12:04:09 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	check_extension(char *filename)
{
	char	*extension;

	extension = ft_strchr(filename, '.');
	extension = ft_strtrim(extension, " \t\r\v\f\n");
	if (!extension)
	{
		write(2, "Missing extension, '.rt' required\n", 34);
		return (false);
	}
	else if (ft_strncmp(extension, ".rt", 4))
	{
		write(2, "Invalid extension, '.rt' required\n", 34);
		free(extension);
		return (false);
	}
	free(extension);
	return (true);
}

int	is_input_ok(int argc, char **argv)
{
	if (argc < 2)
	{
		write(2, "Please provide a configuration file\n", 36);
		return (false);
	}
	return (check_extension(argv[1]));
}
