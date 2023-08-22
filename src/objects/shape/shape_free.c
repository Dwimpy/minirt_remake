/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:07:18 by arobu             #+#    #+#             */
/*   Updated: 2023/08/22 22:07:18 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "transform.h"

void	shape_free(t_shape *shape)
{
	free(shape->data);
	tf_free(shape->transform);
}