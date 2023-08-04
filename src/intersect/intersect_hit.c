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
#include "ray.h"
#include "shape.h"
#include "tuple.h"

bool intersect_hit(t_intersections *intersections, t_ray *ray, t_tuple *isec_point, t_tuple *normal, t_shape *shape) {
	int i;

	i = 0;
	if (intersections->count == 0)
		return (false);
	while (i < intersections->count) {
		if (intersections->buffer[i].t > 0) {
			*isec_point = ray_at(*ray, intersections->buffer[i].t);
			*normal = intersections->buffer[i].obj->vtable.normal_at(intersections->buffer[i].obj, *isec_point);
//			tuple_print(intersections->buffer[i].obj->material.color);
			*shape = *intersections->buffer[i].obj;
			return (true);
		}
		i++;
	}
	return (false);
}