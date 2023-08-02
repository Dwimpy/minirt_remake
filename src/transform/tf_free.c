/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tf_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:57:43 by arobu             #+#    #+#             */
/*   Updated: 2023/08/02 21:57:55 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

void		tf_free(t_transform tf)
{
	if (tf.tf.data)
		matrix_free(tf.tf);
	if (tf.inv_tf.data)
		matrix_free(tf.inv_tf);
}