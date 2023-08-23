/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_division.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:10:30 by arobu             #+#    #+#             */
/*   Updated: 2023/08/23 13:13:01 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

__attribute__((unused)) t_color	color_division(t_color a, t_color b)
{
	return (tuple_division(a, b));
}

__attribute__((unused)) t_color	color_division_s(t_color a, t_real s)
{
	return (tuple_division_s(a, s));
}
