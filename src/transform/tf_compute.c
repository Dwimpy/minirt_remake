/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tf_compute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:41:47 by arobu             #+#    #+#             */
/*   Updated: 2023/09/12 18:12:13 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "transform.h"

void	tf_compute(t_transform *transform)
{
	matrix_identity(&transform->tf);
	matrix_multiply(&transform->tf, &transform->tf, &transform->translation);
	matrix_multiply(&transform->tf, &transform->tf, &transform->rotation);
	matrix_multiply(&transform->tf, &transform->tf, &transform->scaling);
	matrix_inverse(&transform->inv_tf, &transform->tf);
	matrix_transpose(&transform->inv_tf_transpose, &transform->inv_tf);
}
