/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_comparator_shape.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 19:58:33 by arobu             #+#    #+#             */
/*   Updated: 2023/08/10 19:58:33 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "shape.h"

bool	vector_comparator_shape(void *element, void *data)
{
	return (*(t_shape **)element == *(t_shape **)data);
}