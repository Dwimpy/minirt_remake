/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:16:49 by arobu             #+#    #+#             */
/*   Updated: 2023/07/31 23:16:49 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vector_clear(t_vector *vector)
{
	ft_memset(vector->buffer, 0, vector->item_size * vector->size);
	vector->size = 0;
}

