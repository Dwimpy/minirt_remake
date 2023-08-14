/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tf_shear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:22:08 by arobu             #+#    #+#             */
/*   Updated: 2023/08/02 21:22:08 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "transform.h"

inline void	tf_shear(t_transform *tf, double xy, double xz, double yx, double yz, double zx, double zy)
{
	matrix_identity(&tf->tf);
	matrix_set(tf->tf, 0, 1, xy);
	matrix_set(tf->tf, 0, 2, xz);
	matrix_set(tf->tf, 1, 0, yx);
	matrix_set(tf->tf, 1, 2, yz);
	matrix_set(tf->tf, 2, 0, zx);
	matrix_set(tf->tf, 2, 1, zy);
}