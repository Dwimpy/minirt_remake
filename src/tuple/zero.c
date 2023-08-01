/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:25:24 by arobu             #+#    #+#             */
/*   Updated: 2023/07/30 18:25:24 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

inline t_tuple	tuple_vector_zero(void)
{
	return ((t_tuple){0.0, 0.0, 0.0, 0.0});
}

inline t_tuple	tuple_point_zero(void)
{
	return ((t_tuple){0.0, 0.0, 0.0, 1.0});
}