/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:32:22 by arobu             #+#    #+#             */
/*   Updated: 2023/07/30 23:32:22 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "tuple.h"

inline t_tuple	ray_at(t_ray ray, t_real t)
{
	return (tuple_add(ray.origin, tuple_multiply_s(ray.direction, t)));
}