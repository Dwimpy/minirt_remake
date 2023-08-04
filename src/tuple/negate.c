/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:51:10 by arobu             #+#    #+#             */
/*   Updated: 2023/07/30 18:51:10 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

inline t_tuple	tuple_negate(t_tuple v)
{
	return ((t_tuple){-1.0 * v.x, -1.0 * v.y, -1.0 * v.z, -1.0 * v.w});
}