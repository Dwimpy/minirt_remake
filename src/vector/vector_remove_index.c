/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_remove_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 19:41:24 by arobu             #+#    #+#             */
/*   Updated: 2023/08/10 19:41:24 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vector_remove_index(t_vector *vector, size_t index)
{
	void	*buffer;
	size_t	bytes_to_shift;

	if (index > vector->size)
		return ;
	buffer = vector_at(vector, index);
	bytes_to_shift = (vector->size - index - 1) * vector->item_size;
	if (bytes_to_shift > 0)
		ft_memmove(buffer, buffer + vector->item_size, bytes_to_shift);
	vector->size--;
}
