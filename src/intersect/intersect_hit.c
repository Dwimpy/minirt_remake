/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_hit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:00:52 by arobu             #+#    #+#             */
/*   Updated: 2023/08/03 20:00:52 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "shape.h"


bool intersect_hit(t_ray *ray, t_computations *comps) {
	t_vector_iterator	it;
	t_intersect			*intersect;

	vector_iterator_begin(&it, &comps->intersections);
	while (!it.end(&it)) {
		intersect = it.get(&it);
		if (intersect->t > 0) {
			comps->point = ray_at(*ray, intersect->t);
			return (intersect_compute(intersect, ray, comps));
		}
		it.next(&it);
	}
	return (false);
}

bool intersect_shadow_hit(t_ray *ray, t_computations *comps, const t_real *distance) {
	t_vector_iterator	it;
	t_intersect			*intersect;

	vector_iterator_begin(&it, &comps->shadow_intersections);
	while (!it.end(&it)) {
		intersect = it.get(&it);
		if (intersect->t > 0) {
			if (intersect->t < *distance)
			{
				comps->is_shadowed = true;
				return (true);
			}
			else
				return (false);
		}
		it.next(&it);
	}
	return (false);
}