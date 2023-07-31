/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:26:23 by arobu             #+#    #+#             */
/*   Updated: 2023/07/31 23:26:23 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	*vector_back(t_vector *vector)
{
	if (vector->size == 0)
		return (NULL);
	return (vector_at(vector, vector->size - 1));
}