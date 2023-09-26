/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rng.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:44:15 by arobu             #+#    #+#             */
/*   Updated: 2023/08/23 16:47:50 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rng.h"

double	random_double(void)
{
	return (drand48());
}

t_tuple	random_vec3(void)
{
	return (tuple_new_vector(random_double(), \
		random_double(), random_double()));
}

t_tuple	random_in_unit_sphere(void)
{
	t_tuple	vec;

	while (1)
	{
		vec = random_vec3();
		if (tuple_magnitude_squared(vec) >= 1)
			continue ;
		return (vec);
	}
}
