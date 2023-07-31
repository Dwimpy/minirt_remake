/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_it_begin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 00:10:49 by arobu             #+#    #+#             */
/*   Updated: 2023/08/01 00:10:49 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	*vector_iterator_get(t_vector_iterator *it)
{
	return (it->ptr->buffer + it->index * it->ptr->item_size);
}

void	vector_iterator_next(t_vector_iterator *it)
{
	it->index++;
}

bool	vector_iterator_equal(t_vector_iterator *lhs)
{
	return (lhs->index == lhs->ptr->size);
}

void	vector_iterator_end(t_vector_iterator *it, t_vector *vector)
{
	it->ptr = vector;
	it->index = vector->size;
	it->next = vector_iterator_next;
	it->get = vector_iterator_get;
	it->end = vector_iterator_equal;
}

void 	vector_iterator_begin(t_vector_iterator *it, t_vector *vector)
{
	it->index = 0;
	it->ptr = vector;
	it->next = vector_iterator_next;
	it->get = vector_iterator_get;
	it->end = vector_iterator_equal;
}
