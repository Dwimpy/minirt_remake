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

# include "camera.h"
#include "matrix.h"
#include "ray.h"
#include "tuple.h"

t_ray camera_get_ray(t_camera *camera, size_t x, size_t y) {
	t_real x_offset;
	t_real y_offset;
	t_tuple world_coord;
	t_tuple pixel_origin;
	t_tuple ray_origin;

	x_offset = ((t_real) x + 0.5) * camera->pixel_size;
	y_offset = ((t_real) y + 0.5) * camera->pixel_size;
	world_coord = tuple_new_point(camera->half_width - x_offset, camera->half_height - y_offset, -1);
	pixel_origin = matrix_multiply_tuple(camera->tf.inv_tf, world_coord);
	ray_origin = matrix_multiply_tuple(camera->tf.inv_tf, tuple_new_point(0, 0, 0));
	return (ray_new(ray_origin, tuple_normalize(tuple_subtract(pixel_origin, ray_origin))));
}