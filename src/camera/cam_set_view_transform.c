/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_set_view_transform.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:57:39 by arobu             #+#    #+#             */
/*   Updated: 2023/08/09 21:57:39 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "transform.h"

void camera_set_view_transform(t_camera *camera, t_transform vt)
{
	if (camera->tf.tf.data)
		tf_free(camera->tf);
	camera->tf = vt;
}