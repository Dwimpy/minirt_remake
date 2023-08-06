/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:20:23 by arobu             #+#    #+#             */
/*   Updated: 2023/08/03 20:20:23 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "transform.h"

t_ray ray_transform(t_ray *ray, t_transform tf)
{
	t_ray	new_ray;

	new_ray.origin = ray->origin;
	new_ray.direction = ray->direction;
	new_ray.origin = matrix_multiply_tuple(tf.inv_tf, ray->origin);
	new_ray.direction = matrix_multiply_tuple(tf.inv_tf, ray->direction);
	return (new_ray);
}