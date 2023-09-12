/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:53:47 by arobu             #+#    #+#             */
/*   Updated: 2023/09/12 16:11:32 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

void	shape_rotate(t_shape *shape, double x, double y, double z)
{
	tf_rotate_z(&shape->transform, z);
}
