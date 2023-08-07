/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:37:52 by arobu             #+#    #+#             */
/*   Updated: 2023/08/06 15:37:52 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
#include "transform.h"
# include "tuple.h"
# include "ray.h"
# include "onb.h"
# include <stdint.h>

typedef struct s_camera
{
	uint32_t	width;
	uint32_t	height;
	double		fov;
	double		aspect_ratio;
	double		half_width;
	double		half_height;
	double		half_view;
	double		pixel_size;
	t_onb		onb;
	t_transform	tf;
}				t_camera;

t_camera	camera_new(uint32_t width, uint32_t height, double fov);
t_ray		camera_get_ray(t_camera *cam, size_t x, size_t y);
t_transform	camera_view_transform(t_tuple from, t_tuple to);

#endif