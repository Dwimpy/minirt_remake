/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:27:37 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/05 14:17:32 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser/parser.h"
#include "libft.h"
#include "vector.h"
#include "stdio.h"

void	free_data(t_data *data)
{
	free(data->ambient);
	free(data->camera);
	free(data->light);
	free(data->resolution);
	free(data->cylinder);
	free(data->plane);
	free(data->sphere);
}


void	test_init(void)
{
	t_data	*data;

	data = initialize_data();
	printf("[%i]\n", data->resolution->high);
	free_data(data);
}
