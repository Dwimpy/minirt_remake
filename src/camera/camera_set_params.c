/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_set_params.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:40:50 by arobu             #+#    #+#             */
/*   Updated: 2023/08/14 15:40:50 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "transform.h"

void camera_set_params(t_camera *camera, int32_t width, uint32_t height, double fov)
{
	camera->width = width;
	camera->height = height;
	camera->fov = tf_deg_to_rad(fov);
	camera->half_view = tan(camera->fov / 2.0);
	camera->aspect_ratio = (double) camera->width / (double) camera->height;
	if (is_approx_equal(\
        camera->aspect_ratio, 1.0, M_EPSILON) || camera->aspect_ratio > 1.0)
	{
		camera->half_width = camera->half_view;
		camera->half_height = camera->half_view / camera->aspect_ratio;
	} else
	{
		camera->half_width = camera->half_view * camera->aspect_ratio;
		camera->half_height = camera->half_view;
	}
	camera->pixel_size = (camera->half_width * 2.0) / (double)camera->width;
	tf_reset(&camera->tf);
}