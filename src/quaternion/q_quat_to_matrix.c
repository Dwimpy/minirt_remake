/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_quat_to_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 21:56:37 by arobu             #+#    #+#             */
/*   Updated: 2023/08/07 21:56:37 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "quaternion.h"

t_matrix	quat_to_matrix(t_quaternion q)
{
	t_real		sq_qw;
	t_real		sq_qx;
	t_real		sq_qy;
	t_real		sq_qz;
	t_real		invs;
	t_matrix	rot;

	sq_qw = q.w * q.w;
	sq_qx = q.x * q.x;
	sq_qy = q.y * q.y;
	sq_qz = q.z * q.z;
	rot = matrix_identity();
	invs = 1.0 / (sq_qw + sq_qx + sq_qy + sq_qz);
	rot.data[0][0] = (sq_qx - sq_qy - sq_qz + sq_qw) * invs;
	rot.data[1][1] = (-sq_qx + sq_qy - sq_qz + sq_qw) * invs;
	rot.data[2][2] = (-sq_qx - sq_qy + sq_qz + sq_qw) * invs;
	rot.data[0][1] = 2.0 * (q.x * q.y - q.z * q.w) * invs;
	rot.data[0][2] = 2.0 * (q.x * q.z + q.y * q.w) * invs;
	rot.data[1][0] = 2.0 * (q.x * q.y + q.z * q.w) * invs;
	rot.data[1][2] = 2.0 * (q.y * q.z - q.x * q.w) * invs;
	rot.data[2][0] = 2.0 * (q.x * q.z - q.y * q.w) * invs;
	rot.data[2][1] = 2.0 * (q.y * q.z - q.x * q.w) * invs;
	return (rot);
}