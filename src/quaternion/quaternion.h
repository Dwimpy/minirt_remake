/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:41:04 by arobu             #+#    #+#             */
/*   Updated: 2023/08/07 20:41:04 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUATERNION_H
# define QUATERNION_H
# include <math.h>
# include "matrix.h"
# include "tuple.h"
# include "transform.h"

typedef double	t_real;

typedef struct s_quaternion
{
	t_real		x;
	t_real		y;
	t_real		z;
	t_real		w;
}				t_quaternion;

typedef struct s_euler
{
	t_real		roll;
	t_real		pitch;
	t_real		yaw;
}				t_euler;

typedef struct s_quat_params
{
	t_real		cr;
	t_real		sr;
	t_real		cp;
	t_real		sp;
	t_real		cy;
	t_real		sy;
}				t_quat_params;

t_quaternion	quaternion_new(t_real x, t_real y, t_real z, t_real w);
t_quaternion	quat_rot_from_to(t_tuple from, t_tuple to);
t_quaternion	quat_multiply(t_quaternion q1, t_quaternion q2);
t_quaternion	quat_conjugate(t_quaternion q);
t_matrix		quat_to_matrix(t_quaternion q);
t_tuple			quat_rotate_vector(t_tuple v, t_quaternion q);
#endif
