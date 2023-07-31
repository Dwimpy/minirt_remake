/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magnitude_squared.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:52:40 by arobu             #+#    #+#             */
/*   Updated: 2023/07/31 18:52:40 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

inline t_real	vec3_magnitude_squared(t_vec3 v)
{
	double len;

	len = vec3_magnitude(v);
	return (len * len);
}