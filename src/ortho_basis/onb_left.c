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

t_onb	onb_create_left(void)
{
	t_onb	onb;
	t_tuple	tmp;

	onb.forward = tuple_new_vector(0, 0, 1);
	onb.left = tuple_normalize(tuple_cross(onb.forward, tuple_new_vector(0, 1, 0)));
	onb.up = tuple_cross(onb.left, onb.forward);
	return (onb);
}