/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:45:24 by arobu             #+#    #+#             */
/*   Updated: 2023/08/06 15:45:24 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "tuple.h"
#include <stdio.h>

t_camera camera_new(uint32_t width, uint32_t height, double fov) {
	t_camera cam;

	cam.width = width;
	cam.height = height;
	cam.fov = fov;
	cam.half_view = tan(cam.fov / 2.0);
	cam.aspect_ratio = (double) cam.width / (double) cam.height;
	if (is_approx_equal(cam.aspect_ratio, 1.0, M_EPSILON) || cam.aspect_ratio > 1.0)
	{
		cam.half_width = cam.half_view;
		cam.half_height = cam.half_view / cam.aspect_ratio;
	}
	else
	{
		cam.half_width = cam.half_view * cam.aspect_ratio;
		cam.half_height = cam.half_view;
	}
	cam.pixel_size = (cam.half_width * 2.0) / (double)cam.width;
	cam.tf = tf_new();
	return (cam);
}