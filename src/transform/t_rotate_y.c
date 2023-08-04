/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_rotate_y.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 20:03:43 by arobu             #+#    #+#             */
/*   Updated: 2023/08/02 20:03:43 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "transform.h"

inline t_transform tf_rotate_y(double degrees) {
	t_transform transform;
	double rads;

	rads = tf_deg_to_rad(degrees);
	transform.tf = matrix_identity();
	matrix_set(transform.tf, 0, 0, cos(rads));
	matrix_set(transform.tf, 0, 2, sin(rads));
	matrix_set(transform.tf, 2, 0, -sin(rads));
	matrix_set(transform.tf, 2, 2, cos(rads));
	transform.inv_tf = matrix_inverse(transform.tf);
	transform.tf_transpose = matrix_transpose(transform.tf);
	transform.inv_tf_transpose = matrix_transpose(transform.inv_tf);
	return (transform);
}