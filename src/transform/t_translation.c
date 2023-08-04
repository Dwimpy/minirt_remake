/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_translation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:17:09 by arobu             #+#    #+#             */
/*   Updated: 2023/08/02 18:17:09 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "transform.h"

inline t_transform tf_translate(double x, double y, double z) {
	t_transform transform;

	transform.tf = matrix_identity();
	matrix_set(transform.tf, 0, 3, x);
	matrix_set(transform.tf, 1, 3, y);
	matrix_set(transform.tf, 2, 3, z);
	transform.inv_tf = matrix_inverse(transform.tf);
	transform.tf_transpose = matrix_transpose(transform.tf);
	transform.inv_tf_transpose = matrix_transpose(transform.inv_tf);
	return (transform);
}