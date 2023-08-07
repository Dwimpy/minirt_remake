/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:56:32 by arobu             #+#    #+#             */
/*   Updated: 2023/08/07 16:18:39 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "ray.h"
#include "shape.h"
#include "sphere.h"
#include "tuple.h"
#include <math.h>

static bool	\
	sphere_compute_quadratic(t_quadratic *params, \
							t_shape *shape, \
							t_ray *ray)
{
	t_sphere	*sphere;
	t_tuple		sph_to_ray;
	double		sqrt_disc;

	sphere = shape_get_data(shape);
	*ray = ray_to_object_space(ray, shape->transform);
	sph_to_ray = tuple_subtract(ray->origin, sphere->origin);
	params->a = tuple_dot(ray->direction, ray->direction);
	params->b = 2 * tuple_dot(ray->direction, sph_to_ray);
	params->c = tuple_dot(sph_to_ray, sph_to_ray) - \
		sphere->radius * sphere->radius;
	params->disc = params->b * params->b - 4 * params->a * params->c;
	if (params->disc < 0)
		return (false);
	sqrt_disc = sqrt(params->disc);
	params->t1 = (-params->b - sqrt_disc) / (2 * params->a);
	params->t2 = (-params->b + sqrt_disc) / (2 * params->a);
	return (true);
}

static bool	\
	sphere_add_intersections(t_vector *intersections, \
							t_quadratic *params, \
							t_shape *shape)
{
	if (is_approx_equal(params->t1, params->t2, M_EPSILON))
		vector_pushback_intersect(intersections, params->t1, shape);
	else
	{
		vector_pushback_intersect(intersections, params->t1, shape);
		vector_pushback_intersect(intersections, params->t2, shape);
	}
	return (true);
}

bool	sphere_intersect(t_shape *shape, t_ray ray, t_vector *intersections)
{
	t_quadratic	params;

	if (!sphere_compute_quadratic(&params, shape, &ray))
		return (false);
	return (sphere_add_intersections(intersections, &params, shape));
}
