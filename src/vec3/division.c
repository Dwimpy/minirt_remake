/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_division_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:33:15 by arobu             #+#    #+#             */
/*   Updated: 2023/07/30 18:33:15 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

inline t_vec3	vec3_division(t_vec3 v1, t_vec3 v2)
{
	return ((t_vec3){v1.x / v2.x, v1.y / v2.y, v1.z / v2.z});
}

inline t_vec3	vec3_division_s(t_vec3 v1, t_real s)
{
	return ((t_vec3){v1.x / s, v1.y / s, v1.z / s});
}