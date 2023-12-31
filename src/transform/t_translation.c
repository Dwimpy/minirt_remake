/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_translation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:17:09 by arobu             #+#    #+#             */
/*   Updated: 2023/08/08 03:47:15 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "transform.h"

inline void	tf_translate(t_transform *tf, double x, double y, double z)
{
	matrix_identity(&tf->translation);
	matrix_set(tf->translation, 0, 3, x);
	matrix_set(tf->translation, 1, 3, y);
	matrix_set(tf->translation, 2, 3, z);
}
