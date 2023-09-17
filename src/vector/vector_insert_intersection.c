/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_insert_intersection.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:47:32 by arobu             #+#    #+#             */
/*   Updated: 2023/08/08 02:57:24 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vector.h"

void	vector_pushback_intersect(t_vector *vector, t_real t, t_shape *shape)
{
	size_t			idx;
	size_t			byte_shift;
	void			*buffer;

	if (shape == NULL)
	{
		write(1, VECTOR_ADD_INTERSECTION_NULL, sizeof(VECTOR_ADD_INTERSECTION_NULL));
		exit(1);
	}
	vector_resize(vector);
	idx = vector_binary_search(vector, t);
	buffer = vector_at(vector, idx);
	byte_shift = (vector->size - idx) * vector->item_size;
	if (byte_shift > 0)
		ft_memmove(buffer + vector->item_size, buffer, byte_shift);
	ft_memcpy(buffer, &t, sizeof(t_real));
	ft_memcpy(buffer + sizeof(t_real), &shape, sizeof(t_shape *));
	vector->size++;
}
