/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:36:18 by arobu             #+#    #+#             */
/*   Updated: 2023/08/04 16:36:18 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	ray_set(t_ray *ray, t_tuple origin, t_tuple direction)
{
	ray->origin = origin;
	ray->direction = direction;
}