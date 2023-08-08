/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:16:23 by arobu             #+#    #+#             */
/*   Updated: 2023/08/08 17:19:27 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vector_remove_front(t_vector *vector)
{
	void	*buffer;

	if (vector->size <= 1)
		return ;
	buffer = vector_front(vector);
	ft_memmove(buffer, \
			buffer + vector->item_size, \
			vector->item_size * (vector->size - 1));
	vector->size--;
}