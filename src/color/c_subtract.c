/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtract.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 00:37:57 by arobu             #+#    #+#             */
/*   Updated: 2023/08/23 13:13:13 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

__attribute__((unused)) t_color	color_subtract(t_color a, t_color b)
{
	return (tuple_subtract(a, b));
}
