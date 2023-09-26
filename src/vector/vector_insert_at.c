/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_insert_at.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:45:59 by arobu             #+#    #+#             */
/*   Updated: 2023/09/22 15:58:13 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdio.h>
#include <string.h>

bool	vector_insert_at(t_vector *vector, size_t index, void *elem)
{
	void	*buf;

	if (index >= vector->size)
		return (vector_pushback(vector, elem));
	vector_resize(vector);
	buf = vector_at(vector, index);
	ft_memmove(buf + vector->item_size, buf, \
		(vector->size - index) * vector->item_size);
	ft_memmove(buf, elem, vector->item_size);
	vector->size++;
	return (true);
}
