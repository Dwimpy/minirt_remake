/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tf_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:48:37 by arobu             #+#    #+#             */
/*   Updated: 2023/08/06 16:48:37 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "transform.h"

inline t_transform tf_transform(t_transform rotate, t_transform scale, t_transform translate) {
	t_transform transform;
	t_matrix	trans_scale;

	trans_scale = matrix_multiply(matrix_multiply(translate.tf, scale.tf), rotate.tf);
	transform.tf = trans_scale;
	transform.inv_tf = matrix_inverse(transform.tf);
	transform.tf_transpose = matrix_transpose(transform.tf);
	transform.inv_tf_transpose = matrix_transpose(transform.inv_tf);
	tf_free(rotate);
	tf_free(scale);
	tf_free(translate);
	return (transform);
}