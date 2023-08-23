/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onb_left.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:31:39 by arobu             #+#    #+#             */
/*   Updated: 2023/08/16 15:31:39 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "onb.h"
#include "tuple.h"

t_onb	onb_create_left(t_tuple normal)
{
	t_onb	onb;

	onb.up = tuple_normalize(normal);
	onb.forward = tuple_normalize(\
		tuple_cross(onb.up, tuple_new_vector(0, 1, 0)));
	if (tuple_magnitude(onb.forward) < M_EPSILON)
		onb.forward = tuple_normalize(\
			tuple_cross(onb.up, tuple_new_vector(1, 0, 0)));
	onb.left = tuple_cross(onb.up, onb.forward);
	return (onb);
}
