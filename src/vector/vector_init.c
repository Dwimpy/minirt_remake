/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:14:47 by arobu             #+#    #+#             */
/*   Updated: 2023/07/31 23:14:47 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector vector_init(size_t capacity, size_t n_size) {
	t_vector vector;

	vector.buffer = ft_calloc(capacity, n_size);
	vector.size = 0;
	vector.item_size = n_size;
	vector.capacity = capacity;
	return (vector);
}