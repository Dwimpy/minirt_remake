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

inline void	tf_rotate_x(t_transform *tf, double degrees)
{
	double		rads;

	rads = tf_deg_to_rad(degrees);
	matrix_identity(&tf->rotation);
	matrix_set(tf->rotation, 1, 1, cos(rads));
	matrix_set(tf->rotation, 1, 2, -sin(rads));
	matrix_set(tf->rotation, 2, 1, sin(rads));
	matrix_set(tf->rotation, 2, 2, cos(rads));
}
