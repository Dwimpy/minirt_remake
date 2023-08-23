/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tf_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:42:57 by arobu             #+#    #+#             */
/*   Updated: 2023/08/02 21:42:57 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "transform.h"

inline void	tf_rotate(t_transform *tf, double deg_x, double deg_y, double deg_z)
{
	double		a;
	double		b;
	double		g;

	a = tf_deg_to_rad(deg_z);
	b = tf_deg_to_rad(deg_y);
	g = tf_deg_to_rad(deg_x);
	matrix_set(tf->rotation, 0, 0, cos(a) * cos(b));
	matrix_set(tf->rotation, 1, 0, sin(a) * cos(b));
	matrix_set(tf->rotation, 2, 0, -sin(b));
	matrix_set(tf->rotation, 0, 1, cos(a) * sin(b) * sin(g) - sin(a) * cos(g));
	matrix_set(tf->rotation, 1, 1, sin(a) * sin(b) * sin(g) + cos(a) * cos(g));
	matrix_set(tf->rotation, 2, 1, cos(b) * sin(g));
	matrix_set(tf->rotation, 0, 2, cos(a) * sin(b) * cos(g) + sin(a) * sin(g));
	matrix_set(tf->rotation, 1, 2, sin(a) * sin(b) * cos(g) - cos(a) * sin(g));
	matrix_set(tf->rotation, 2, 2, cos(b) * cos(g));
}
