/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:02:06 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/05 13:58:14 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser/parser.h"
#include "libft.h"
#include "vector.h"
#include "stdio.h"

t_ambient	*initialize_ambient(void)
{
	t_ambient	*ambient;

	ambient = malloc(sizeof(t_ambient));
	ambient->idx = 0;
	ambient->ambient_ratio = 0;
	ambient->r = 0;
	ambient->g = 0;
	ambient->b = 0;
	return (ambient);
}

t_res	*initiliaze_res(void)
{
	t_res	*res;

	res = malloc(sizeof(t_res));
	res->idx = 0;
	res->width = 0;
	res->high = 0;
	return (res);
}

t_data	*initialize_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->ambient = initialize_ambient();
	data->camera = initialize_camera();
	data->resolution = initiliaze_res();
	data->light = initialize_light();
	data->sphere = initialize_sp();
	data->plane = initialize_pl();
	data->cylinder = initialize_cy();
	return (data);
}
