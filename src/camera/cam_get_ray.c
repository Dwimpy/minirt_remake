/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_get_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:56:04 by arobu             #+#    #+#             */
/*   Updated: 2023/08/06 15:56:04 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_ray	camera_get_ray(t_camera *camera, size_t x, size_t y, t_sample sample)
{
	t_tuple	world_coord;
	t_tuple	pixel_origin;
	t_tuple	ray_origin;

	world_coord = tuple_new_point(\
		camera->half_width - \
			(((t_real) x - sample.x) + 0.5) * \
			camera->pixel_size, \
		camera->half_height - \
			(((t_real) y - sample.y) + 0.5) * \
			camera->pixel_size, -1);
	pixel_origin = matrix_multiply_tuple(\
		camera->tf.inv_tf, world_coord);
	ray_origin = matrix_multiply_tuple(\
		camera->tf.inv_tf, tuple_new_point(0, 0, 0));
	return (ray_new(ray_origin, \
		tuple_normalize(\
			tuple_subtract(pixel_origin, ray_origin))));
}
