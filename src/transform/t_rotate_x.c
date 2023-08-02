/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:39:56 by arobu             #+#    #+#             */
/*   Updated: 2023/08/02 19:39:56 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "transform.h"

inline t_transform tf_rotate_x(double degrees)
{
	t_transform	transform;
	double		rads;

	rads = tf_deg_to_rad(degrees);
	transform.tf = matrix_identity();
	matrix_set(transform.tf, 1, 1, cos(rads));
	matrix_set(transform.tf, 1, 2, -sin(rads));
	matrix_set(transform.tf, 2, 1, sin(rads));
	matrix_set(transform.tf, 2, 2, cos(rads));
	transform.inv_tf = matrix_inverse(transform.tf);
	return (transform);
}