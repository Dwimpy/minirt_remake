/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tf_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:57:43 by arobu             #+#    #+#             */
/*   Updated: 2023/08/08 03:39:18 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "transform.h"

void	tf_free(t_transform tf)
{
	if (tf.tf.data)
		matrix_free(tf.tf);
	if (tf.inv_tf.data)
		matrix_free(tf.inv_tf);
	if (tf.inv_tf_transpose.data)
		matrix_free(tf.inv_tf_transpose);
	if (tf.translation.data)
		matrix_free(tf.translation);
	if (tf.translation.data)
		matrix_free(tf.rotation);
	if (tf.translation.data)
		matrix_free(tf.scaling);
}
