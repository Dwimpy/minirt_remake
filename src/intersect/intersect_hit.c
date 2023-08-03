/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_hit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:00:52 by arobu             #+#    #+#             */
/*   Updated: 2023/08/03 20:00:52 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"

bool	intersect_hit(t_intersect *intersection)
{
	if (intersection->t[0] > 0 || intersection->t[1] > 0)
		return (true);
	return (false);
}