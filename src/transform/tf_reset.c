/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tf_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:02:33 by arobu             #+#    #+#             */
/*   Updated: 2023/08/14 16:02:33 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

void	tf_reset(t_transform *tf)
{
	matrix_identity(&tf->translation);
	matrix_identity(&tf->rotation);
	matrix_identity(&tf->scaling);
	matrix_identity(&tf->tf);
	matrix_identity(&tf->inv_tf_transpose);
	matrix_identity(&tf->inv_tf);
}
