/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_tf_reset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:22:15 by arobu             #+#    #+#             */
/*   Updated: 2023/08/14 18:22:15 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	camera_tf_reset(t_camera *camera)
{
	matrix_identity(&camera->tf.translation);
	matrix_identity(&camera->tf.rotation);
	matrix_identity(&camera->tf.scaling);
}