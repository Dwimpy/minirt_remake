/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:30:28 by arobu             #+#    #+#             */
/*   Updated: 2023/08/04 13:30:28 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "libft.h"

void initialize_intersections(t_intersections *intersections) {
	intersections->count = 0;
	ft_memset(intersections->buffer, 0, MAX_INTERSECTIONS_PER_OBJECT * sizeof(t_intersect));
}