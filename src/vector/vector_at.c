/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:15:45 by arobu             #+#    #+#             */
/*   Updated: 2023/07/31 23:15:45 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

inline void	*vector_at(t_vector *vector, size_t index)
{
	if (vector->size > 0 && index > vector->size)
	{
		write(2, VECTOR_IDX_OUT_OF_BOUNDS, 40);
		return (NULL);
	}
	return (vector->buffer + (index * vector->item_size));
}
