/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rng.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:44:15 by arobu             #+#    #+#             */
/*   Updated: 2023/07/31 18:44:15 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rng.h"
#include "vec3.h"

double random_double() {
	return (drand48());
}

t_vec3 random_vec3() {
	return ((t_vec3) {random_double(), random_double(), random_double()});
}

t_vec3 random_in_unit_sphere() {
	t_vec3 vec;
	while (1) {
		vec = random_vec3();
		if (vec3_magnitude_squared(vec) >= 1)
			continue ;
		return (vec);
	}
}