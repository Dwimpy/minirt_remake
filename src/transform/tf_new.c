/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tf_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:57:59 by arobu             #+#    #+#             */
/*   Updated: 2023/08/14 15:20:46 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "transform.h"

t_transform	tf_new(void)
{
	t_transform	tf;

	tf.translation = matrix_init(4, 4);
	tf.rotation = matrix_init(4, 4);
	tf.scaling = matrix_init(4, 4);
	tf.tf = matrix_init(4, 4);
	tf.inv_tf = matrix_init(4, 4);
	tf.inv_tf_transpose = matrix_init(4, 4);
	return (tf);
}
