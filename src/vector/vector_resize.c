/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:16:27 by arobu             #+#    #+#             */
/*   Updated: 2023/09/05 15:42:54 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int	vector_resize(t_vector *vector)
{
	void	*new_buffer;

	if (vector->size == SIZE_MAX)
		return (2);
	else if (vector->size == vector->capacity)
	{
		new_buffer = malloc(vector->capacity * 2 * vector->item_size);
		if (!new_buffer)
		{
			write(2, VECTOR_RESIZE_FAILED, 48);
			return (2);
		}
		vector->capacity *= 2;
		ft_memcpy(new_buffer, vector->buffer, vector->size * vector->item_size);
		free(vector->buffer);
		vector->buffer = NULL;
		vector->buffer = new_buffer;
		return (1);
	}
	return (0);
}
