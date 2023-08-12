/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion_conjugate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 22:25:36 by arobu             #+#    #+#             */
/*   Updated: 2023/08/12 22:25:36 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"

t_quaternion	quat_conjugate(t_quaternion q)
{
	t_quaternion	q_conj;

	q_conj.w = q.w;
	q_conj.x = -q.x;
	q_conj.y = -q.y;
	q_conj.z = -q.z;
	return (q_conj);
}
