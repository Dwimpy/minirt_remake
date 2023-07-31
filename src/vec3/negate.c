/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:51:10 by arobu             #+#    #+#             */
/*   Updated: 2023/07/30 18:51:10 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

inline t_vec3	vec3_negate(t_vec3 v)
{
	return ((t_vec3){-1.0 * v.x, -1.0 * v.y, -1.0 * v.z});
}