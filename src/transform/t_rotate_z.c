/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_rotate_z.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 20:03:45 by arobu             #+#    #+#             */
/*   Updated: 2023/08/02 20:03:45 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "transform.h"

inline void	tf_rotate_z(t_transform *tf, double degrees)
{
	double	rads;

	rads = tf_deg_to_rad(degrees);
	matrix_identity(&tf->rotation);
	matrix_set(tf->rotation, 0, 0, cos(rads));
	matrix_set(tf->rotation, 0, 1, -sin(rads));
	matrix_set(tf->rotation, 1, 0, sin(rads));
	matrix_set(tf->rotation, 1, 1, cos(rads));
}
