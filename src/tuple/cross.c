/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:49:20 by arobu             #+#    #+#             */
/*   Updated: 2023/07/30 19:49:20 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

inline t_tuple	tuple_cross(t_tuple v1, t_tuple v2)
{
	return (tuple_new_vector(\
		v1.y * v2.z - v1.z * v2.y, \
		v1.z * v2.x - v1.x * v2.z, \
		v1.x * v2.y - v1.y * v2.x));
}
