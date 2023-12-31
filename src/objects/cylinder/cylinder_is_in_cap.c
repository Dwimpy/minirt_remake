/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_is_in_cap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 18:00:04 by arobu             #+#    #+#             */
/*   Updated: 2023/08/23 16:37:20 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

bool	cylinder_is_in_cap(t_ray *ray, t_real const *t)
{
	t_tuple	point;

	point = ray_at(*ray, *t);
	return ((point.x * point.x + point.z * point.z) <= 1.0);
}
