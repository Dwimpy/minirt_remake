/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 01:44:14 by arobu             #+#    #+#             */
/*   Updated: 2023/07/31 01:44:14 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_INTERNAL_H
# define MATRIX_INTERNAL_H

#include "stdbool.h"

static bool	is_elem_out_of_range(int row, int column, int dimension)
{
	return ((row - 1) > dimension || \
			(column - 1) > dimension || \
			(row - 1) < 0 || \
			(column - 1) < 0);
}

#endif