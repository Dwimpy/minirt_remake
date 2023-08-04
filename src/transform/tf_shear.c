/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tf_shear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:22:08 by arobu             #+#    #+#             */
/*   Updated: 2023/08/02 21:22:08 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "transform.h"

inline t_transform tf_shear(double xy, double xz, double yx, double yz, double zx, double zy)
{
	t_transform transform;

	transform.tf = matrix_identity();
	matrix_set(transform.tf, 0, 1, xy);
	matrix_set(transform.tf, 0, 2, xz);
	matrix_set(transform.tf, 1, 0, yx);
	matrix_set(transform.tf, 1, 2, yz);
	matrix_set(transform.tf, 2, 0, zx);
	matrix_set(transform.tf, 2, 1, zy);
	transform.inv_tf = matrix_inverse(transform.tf);
	transform.tf_transpose = matrix_transpose(transform.tf);
	transform.inv_tf_transpose = matrix_transpose(transform.inv_tf);
	return (transform);
}