/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_set_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:31:03 by arobu             #+#    #+#             */
/*   Updated: 2023/08/04 16:31:03 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

void	tuple_set(t_tuple *tuple, t_real x, t_real y, t_real z)
{
	tuple->x = x;
	tuple->y = y;
	tuple->z = z;
}
