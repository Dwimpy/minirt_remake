/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_multiply.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 00:38:02 by arobu             #+#    #+#             */
/*   Updated: 2023/07/31 00:38:02 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "tuple.h"

t_color color_multiply(t_color a, t_color b) {
	return (tuple_multiply(a, b));
}

t_color color_multiply_s(t_color c, t_real s)
{
	return (tuple_multiply_s(c, s));
}