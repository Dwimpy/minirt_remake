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

bool	intersect_hit(t_intersect *intersection, double *t)
{
	if (intersection->t[0] > 0 && intersection->t[1] > 0)
	{
		if (intersection->t[0] < intersection->t[1])
			*t = intersection->t[0];
		else
			*t = intersection->t[1];
		return (true);
	}
	else if (intersection->t[0] > 0 && intersection->t[1] < 0)
	{
		*t = intersection->t[0];
		return (true);
	}
	else if (intersection->t[1] > 0 && intersection->t[0] < 0)
	{
		*t = intersection->t[1];
		return (true);
	}
	else
		return (false);
}