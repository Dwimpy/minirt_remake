/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_eul_to_quat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:46:38 by arobu             #+#    #+#             */
/*   Updated: 2023/08/07 20:46:38 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"

inline static t_quaternion	quat_create(t_quat_params p)
{
	t_quaternion	q;

	q.x = p.sr * p.cp * p.cy - p.cr * p.sp * p.sy;
	q.w = p.cr * p.cp * p.cy + p.sr * p.sp * p.sy;
	q.y = p.cr * p.sp * p.cy + p.sr * p.cp * p.sy;
	q.z = p.cr * p.cp * p.sy - p.sr * p.sp * p.cy;
	return (q);
}

t_quaternion	quat_eul_to_quat(t_euler orientation)
{
	t_quat_params	p;

	p.cr = cos(orientation.roll * 0.5);
	p.sr = sin(orientation.roll * 0.5);
	p.cp = cos(orientation.pitch * 0.5);
	p.sp = sin(orientation.pitch * 0.5);
	p.cy = cos(orientation.yaw * 0.5);
	p.sy = sin(orientation.yaw * 0.5);
	return (quat_create(p));
}
