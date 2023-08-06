/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_print_intersections.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:59:27 by arobu             #+#    #+#             */
/*   Updated: 2023/08/05 17:59:27 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "intersect.h"

void	vector_print_intersections(t_vector *vector)
{
	t_vector_iterator	it;
	t_intersect			*intersect;

	vector_iterator_begin(&it, vector);
	printf("Intersection Count: %zu\n", vector->size);
	while (!it.end(&it))
	{
		intersect = (t_intersect  *)it.get(&it);
		printf("%f ", intersect->t);
		it.next(&it);
	}
	printf("\n");
}