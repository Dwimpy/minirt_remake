/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_move_to.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:06:16 by arobu             #+#    #+#             */
/*   Updated: 2023/09/26 13:56:06 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

bool	vector_move_to(t_vector *vector, size_t from, size_t to)
{
	void	*element_from;
	void	*element_to;
	void	*temp;

	element_from = vector_at(vector, from);
	element_to = vector_at(vector, to);
	if (vector->size < 2 || from == to)
		return (false);
	if (from >= 0 && from < vector->size && to >= 0 && to < vector->size)
	{
		temp = malloc(vector->item_size);
		if (temp == NULL)
			return (false);
		ft_memcpy(temp, element_from, vector->item_size);
		ft_memcpy(element_from, element_to, vector->item_size);
		ft_memcpy(element_to, temp, vector->item_size);
		free(temp);
		return (true);
	}
	return (false);
}
