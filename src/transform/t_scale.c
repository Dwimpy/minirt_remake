/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_scale.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:49:11 by arobu             #+#    #+#             */
/*   Updated: 2023/08/02 19:49:11 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "transform.h"

inline void	tf_scale(t_transform *tf, double x, double y, double z)
{
	matrix_identity(&tf->scaling);
	matrix_set(tf->scaling, 0, 0, x);
	matrix_set(tf->scaling, 1, 1, y);
	matrix_set(tf->scaling, 2, 2, z);
}
