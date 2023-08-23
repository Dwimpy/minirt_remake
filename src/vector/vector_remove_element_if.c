/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_remove_element_if.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 19:54:10 by arobu             #+#    #+#             */
/*   Updated: 2023/08/10 19:54:10 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

bool	vector_remove_element_if(\
	t_vector *vector, t_vector_comparator compare, void	*data)
{
	size_t	i;

	i = 0;
	if (!data)
		return (false);
	while (i < vector->size)
	{
		if (compare(vector->buffer + i * vector->item_size, data))
		{
			vector_remove_index(vector, i);
			return (true);
		}
		else
			i++;
	}
	return (false);
}
