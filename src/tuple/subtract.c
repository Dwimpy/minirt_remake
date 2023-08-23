/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtract.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:28:11 by arobu             #+#    #+#             */
/*   Updated: 2023/07/30 18:28:11 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

inline t_tuple	tuple_subtract(t_tuple v1, t_tuple v2)
{
	return ((t_tuple){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w});
}
