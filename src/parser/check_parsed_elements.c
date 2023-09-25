/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsed_elements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:39:28 by arobu             #+#    #+#             */
/*   Updated: 2023/09/25 12:33:31 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "hooks.h"
#include "libft.h"
#include "parser.h"

static int	check_mandatory_elements(t_vector *vector)
{
	char	**str;
	size_t	i;

	i = 0;
	while (i < 4)
	{
		str = *(char ***)vector_at(vector, i);
		if (ft_strncmp(str[0], "R", 2) && ft_strncmp(str[0], "C", 2) && \
				ft_strncmp(str[0], "A", 2) && ft_strncmp(str[0], "L", 2))
			return (0);
		i++;
	}
	return (1);
}

void	key_binds(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

int	black_screen(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(1920, 1080, "MINIRT", true);
	if (!mlx)
		return (EXIT_FAILURE);
	mlx_loop_hook(mlx, key_binds, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

void	check_inside(t_vector *vector)
{
	char	**str;

	str = *(char ***)vector_at(vector, 0);

	if (!ft_strncmp(str[0], "R", 2) || !ft_strncmp(str[0], "C", 2) || \
				!ft_strncmp(str[0], "A", 2) || !ft_strncmp(str[0], "L", 2))

	{
		black_screen();
		shut_down_parser(*vector, "Too few values");
	}
}

int	check_parsed_data(t_vector *parsed_data)
{
	if (parsed_data->size == 1)
		check_inside(parsed_data);
	else if (parsed_data->size < 4)
		return (0);
	return (check_mandatory_elements(parsed_data));
}
