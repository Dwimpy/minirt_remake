/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_binary_search.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:34:07 by arobu             #+#    #+#             */
/*   Updated: 2023/09/04 16:36:39 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
//#include <sys/_types/_size_t.h>

size_t	vector_binary_search(t_vector *vector, t_real t)
{
	size_t		low;
	size_t		high;
	size_t		mid;
	t_real		mid_t;

	if (vector->size == 0)
		return (0);
	low = 0;
	high = vector->size;
	while (low < high)
	{
		mid = low + (high - low) / 2;
		mid_t = *(double *)vector_at(vector, mid);
		if (mid_t < t)
			low = mid + 1;
		else
			high = mid;
	}
	return (low);
}
