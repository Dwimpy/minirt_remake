/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:31:20 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/05 13:32:55 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser/parser.h"
#include "libft.h"
#include "vector.h"
#include "stdio.h"

t_cy	*initialize_cy(void)
{
	t_cy	*cy;

	cy = malloc(sizeof(t_cy));
	cy->idx = 0;
	cy->x = 0;
	cy->y = 0;
	cy->z = 0;
	cy->vect_x = 0;
	cy->vect_y = 0;
	cy->vect_z = 0;
	cy->diameter = 0;
	cy->height = 0;
	cy->r = 0;
	cy->g = 0;
	cy->b = 0;
	return (cy);
}

t_pl	*initialize_pl(void)
{
	t_pl	*pl;

	pl = malloc(sizeof(t_pl));
	pl->idx = 0;
	pl->x = 0;
	pl->y = 0;
	pl->z = 0;
	pl->vect_x = 0;
	pl->vect_y = 0;
	pl->vect_z = 0;
	pl->r = 0;
	pl->g = 0;
	pl->b = 0;
	return (pl);
}

t_sp	*initialize_sp(void)
{
	t_sp	*sp;

	sp = malloc(sizeof(t_sp));
	sp->idx = 0;
	sp->x = 0;
	sp->y = 0;
	sp->z = 0;
	sp->diameter = 0;
	sp->r = 0;
	sp->g = 0;
	sp->b = 0;
	return (sp);
}

t_parse_light	*initialize_light(void)
{
	t_parse_light	*light;

	light = malloc(sizeof(t_parse_light));
	light->idx = 0;
	light->x = 0;
	light->y = 0;
	light->z = 0;
	light->ratio = 0;
	light->r = 0;
	light->g = 0;
	light->b = 0;
	return (light);
}

t_parse_camera	*initialize_camera(void)
{
	t_parse_camera	*camera;

	camera = malloc(sizeof(t_parse_camera));
	camera->idx = 0;
	camera->vx = 0;
	camera->vy = 0;
	camera->vz = 0;
	camera->ox = 0;
	camera->oy = 0;
	camera->oz = 0;
	camera->fov = 0;
	return (camera);
}
