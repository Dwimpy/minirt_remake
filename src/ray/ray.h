/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:32:22 by arobu             #+#    #+#             */
/*   Updated: 2023/07/30 23:32:22 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

#include "tuple.h"

typedef struct s_ray
{
	t_tuple		origin;
	t_tuple		direction;
}				t_ray;

t_tuple	ray_value_at(t_ray ray, double t);

#endif