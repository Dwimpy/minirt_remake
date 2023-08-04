/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_scale.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:49:11 by arobu             #+#    #+#             */
/*   Updated: 2023/08/02 19:49:11 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "transform.h"

inline t_transform tf_scale(double x, double y, double z) {
	t_transform transform;

	transform.tf = matrix_identity();
	matrix_set(transform.tf, 0, 0, x);
	matrix_set(transform.tf, 1, 1, y);
	matrix_set(transform.tf, 2, 2, z);
	transform.inv_tf = matrix_inverse(transform.tf);
	transform.tf_transpose = matrix_transpose(transform.tf);
	transform.inv_tf_transpose = matrix_transpose(transform.inv_tf);
	return (transform);
}