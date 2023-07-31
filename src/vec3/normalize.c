/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:53:40 by arobu             #+#    #+#             */
/*   Updated: 2023/07/30 18:53:40 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

inline t_vec3 vec3_normalize(t_vec3 v)
{
	t_real	len;

	len = vec3_magnitude(v);
	return ((t_vec3){v.x / len, v.y / len, v.z / len});
}