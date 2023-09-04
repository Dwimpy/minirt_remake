/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:14:47 by arobu             #+#    #+#             */
/*   Updated: 2023/09/04 13:53:24 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

inline t_vector	vector_init(size_t capacity, size_t n_size)
{
	t_vector	vector;

	vector.buffer = ft_calloc(capacity, n_size);
	vector.size = 0;
	vector.item_size = n_size;
	vector.capacity = capacity;
	return (vector);
}
