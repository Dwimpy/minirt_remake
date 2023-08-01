/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:08:45 by arobu             #+#    #+#             */
/*   Updated: 2023/07/31 16:08:45 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

inline t_tuple tuple_new_vector(t_real x, t_real y, t_real z)
{
	return ((t_tuple){x, y, z, 0.0});
}

inline t_tuple tuple_new_point(t_real x, t_real y, t_real z)
{
	return ((t_tuple){x, y, z, 1.0});
}
