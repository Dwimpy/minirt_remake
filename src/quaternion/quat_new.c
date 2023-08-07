/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:07:18 by arobu             #+#    #+#             */
/*   Updated: 2023/08/07 22:07:18 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"

t_quaternion	quaternion_new(t_real x, t_real y, t_real z, t_real w)
{
	t_quaternion	q;

	q.x = x;
	q.y = y;
	q.z = z;
	q.w = w;
	return (q);
}