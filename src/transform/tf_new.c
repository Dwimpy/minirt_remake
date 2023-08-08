/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tf_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:57:59 by arobu             #+#    #+#             */
/*   Updated: 2023/08/08 03:35:18 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "transform.h"

t_transform	tf_new(void)
{
	t_transform	tf;

	tf.tf = matrix_identity();
	tf.inv_tf.data = NULL;
	tf.inv_tf_transpose.data = NULL;
	tf.tf_transpose.data = NULL;
	return (tf);
}
