/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 00:34:06 by arobu             #+#    #+#             */
/*   Updated: 2023/07/31 00:34:06 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

#include "tuple.h"
#include <stdint.h>

typedef t_tuple	t_color;

t_color		color_new(t_real r, t_real g, t_real b);
t_color		color_division(t_color a, t_color b);
t_color		color_division_s(t_color a, t_real s);
t_color		color_add(t_color a, t_color b);
t_color		color_subtract(t_color a, t_color b);
t_color		color_multiply(t_color a, t_color b);
t_color		color_multiply_s(t_color c, t_real s);
t_color		color_clamp(t_color c);
uint32_t	get_rgba(uint32_t r, uint32_t g, uint32_t b);

#endif