/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_clean.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:19:45 by arobu             #+#    #+#             */
/*   Updated: 2023/07/31 23:19:45 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

inline void	vector_free(t_vector *vector)
{
	if (vector->buffer)
		free(vector->buffer);
	vector->buffer = NULL;
	vector->size = 0;
	vector->capacity = 0;
	vector->item_size = 0;
	vector = NULL;
}
