/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_intersection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:15:57 by arobu             #+#    #+#             */
/*   Updated: 2023/08/09 17:15:57 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"

__attribute__((unused)) t_intersect	intersection(t_real t, t_shape *shape)
{
	return ((t_intersect){t, shape});
}
