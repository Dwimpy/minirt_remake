/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:21:11 by arobu             #+#    #+#             */
/*   Updated: 2023/08/23 16:46:50 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

inline t_ray	ray_to_object_space(t_ray *ray, t_transform tf)
{
	t_ray	new_ray;

	new_ray.origin = ray->origin;
	new_ray.direction = ray->direction;
	new_ray.origin = matrix_multiply_tuple(tf.inv_tf, ray->origin);
	new_ray.direction = matrix_multiply_tuple(tf.inv_tf, ray->direction);
	return (new_ray);
}

inline	t_ray	ray_to_world_space(t_ray *ray, t_transform tf)
{
	t_ray	new_ray;

	new_ray.origin = ray->origin;
	new_ray.direction = ray->direction;
	new_ray.origin = matrix_multiply_tuple(tf.tf, ray->origin);
	new_ray.direction = matrix_multiply_tuple(tf.tf, ray->direction);
	return (new_ray);
}
