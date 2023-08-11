/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_hit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:26:54 by arobu             #+#    #+#             */
/*   Updated: 2023/08/09 17:26:54 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "vector.h"

t_intersect	*intersect_hit(t_vector *intersections)
{
	t_vector_iterator	it;
	t_intersect			*i;

	vector_iterator_begin(&it, intersections);
	while (!it.end(&it))
	{
		i = it.get(&it);
		if (i->t > 0)
			return (i);
		it.next(&it);
	}
	return (NULL);
}