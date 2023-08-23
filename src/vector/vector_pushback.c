/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_pushback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:16:08 by arobu             #+#    #+#             */
/*   Updated: 2023/07/31 23:16:08 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

inline bool	vector_pushback(t_vector *vector, void *data)
{
	void	*buf;

	if (vector_resize(vector) == 2)
		return (false);
	buf = vector_at(vector, vector->size);
	ft_memcpy(buf, data, vector->item_size);
	vector->size++;
	return (true);
}
