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

#include "vec3.h"

typedef t_vec3	t_color;

t_color	color_add(t_color a, t_color b);
t_color	color_subtract(t_color a, t_color b);
t_color	color_multiply(t_color a, t_color b);
t_color color_multiply_s(t_color c, t_real s);