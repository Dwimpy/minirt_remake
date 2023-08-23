/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_rotate_y.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 20:03:43 by arobu             #+#    #+#             */
/*   Updated: 2023/08/14 14:18:30 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "transform.h"

inline void	tf_rotate_y(t_transform *tf, double degrees)
{
	double	rads;

	rads = tf_deg_to_rad(degrees);
	matrix_identity(&tf->rotation);
	matrix_set(tf->rotation, 0, 0, cos(rads));
	matrix_set(tf->rotation, 0, 2, sin(rads));
	matrix_set(tf->rotation, 2, 0, -sin(rads));
	matrix_set(tf->rotation, 2, 2, cos(rads));
}
