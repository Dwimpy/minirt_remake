/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_quat_to_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 21:56:37 by arobu             #+#    #+#             */
/*   Updated: 2023/08/23 16:45:46 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "quaternion.h"

t_matrix	quat_to_matrix(t_quaternion q)
{
	t_quat_to_mtx_computation	p;
	t_matrix					rot;

	p.sq_qw = q.w * q.w;
	p.sq_qx = q.x * q.x;
	p.sq_qy = q.y * q.y;
	p.sq_qz = q.z * q.z;
	rot = matrix_init(4, 4);
	matrix_identity(&rot);
	p.invs = 1.0 / (p.sq_qw + p.sq_qx + p.sq_qy + p.sq_qz);
	rot.data[0][0] = (p.sq_qx - p.sq_qy - p.sq_qz + p.sq_qw) * p.invs;
	rot.data[1][1] = (-p.sq_qx + p.sq_qy - p.sq_qz + p.sq_qw) * p.invs;
	rot.data[2][2] = (-p.sq_qx - p.sq_qy + p.sq_qz + p.sq_qw) * p.invs;
	rot.data[0][1] = 2.0 * (q.x * q.y - q.z * q.w) * p.invs;
	rot.data[0][2] = 2.0 * (q.x * q.z + q.y * q.w) * p.invs;
	rot.data[1][0] = 2.0 * (q.x * q.y + q.z * q.w) * p.invs;
	rot.data[1][2] = 2.0 * (q.y * q.z - q.x * q.w) * p.invs;
	rot.data[2][0] = 2.0 * (q.x * q.z - q.y * q.w) * p.invs;
	rot.data[2][1] = 2.0 * (q.y * q.z - q.x * q.w) * p.invs;
	return (rot);
}
