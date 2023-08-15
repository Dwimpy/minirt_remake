/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_compute.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:54:06 by arobu             #+#    #+#             */
/*   Updated: 2023/08/14 17:54:06 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "matrix.h"
#include "transform.h"
#include "tuple.h"

void	camera_tf_compute(t_camera *camera)
{
	t_matrix trans;

	trans = matrix_init(4, 4);
	matrix_multiply(&trans, &camera->tf.rotation, &camera->tf.translation);
	matrix_multiply(&camera->tf.tf, &camera->tf.tf, &trans);
	matrix_inverse(&camera->tf.inv_tf, &camera->tf.tf);
	matrix_transpose(&camera->tf.inv_tf_transpose, &camera->tf.inv_tf);
	matrix_free(trans);
}