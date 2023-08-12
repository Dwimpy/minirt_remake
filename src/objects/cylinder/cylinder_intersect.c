/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:42:26 by arobu             #+#    #+#             */
/*   Updated: 2023/08/12 15:42:26 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "intersect.h"
#include "quaternion.h"
#include "vector.h"

static bool			solve_quadratic_cylinder(t_quadratic *params, t_ray *ray);
static bool			cylinder_push_intersections(\
	t_quadratic *params, t_ray *ray, t_shape *shape, t_vector *i);
inline static bool		cylinder_check_bounds(\
	const t_real *t, const t_real *y_min, const t_real *y_max, const t_ray *ray);
inline static void		cylinder_intersect_cap(t_ray *ray, t_shape *shape, t_vector *i);


bool	cylinder_intersect(t_shape *shape, t_ray ray, t_vector *intersections)
{
	t_quadratic	params;

	ray = ray_to_object_space(&ray, shape->transform);
	if (!solve_quadratic_cylinder(&params, &ray))
		return (false);
	return (cylinder_push_intersections(&params, &ray, shape, intersections));
}

static bool	solve_quadratic_cylinder(t_quadratic *params, t_ray *ray)
{
	t_real	sqrt_disc;
	t_real	tmp;

	params->a = ray->direction.x * ray->direction.x + \
				ray->direction.z * ray->direction.z;
	if (is_approx_equal(params->a, 0, M_EPSILON))
		return (false);
	params->b = 2 * ray->origin.x * ray->direction.x + \
				2 * ray->origin.z * ray->direction.z;
	params->c = ray->origin.x * ray->origin.x + ray->origin.z * ray->origin.z - 1;
	params->disc = params->b * params->b - 4 * params->a * params->c;
	if (params->disc < 0)
		return (false);
	sqrt_disc = sqrt(params->disc);
	params->t1 = (-params->b - sqrt_disc) / (2 * params->a);
	params->t2 = (-params->b + sqrt_disc) / (2 * params->a);
	if (params->t1 > params->t2)
	{
		tmp = params->t1;
		params->t1 = params->t2;
		params->t2 = tmp;
	}
	return (true);
}

inline static bool	cylinder_check_bounds(\
	const t_real *t, const t_real *y_min, const t_real *y_max, const t_ray *ray)
{
	t_real	y0;

	y0 = ray_at(*ray, *t).y;
	return (y0 > *y_min && y0 < *y_max);
}

static bool	cylinder_push_intersections(\
	t_quadratic *params, t_ray *ray, t_shape *shape, t_vector *i)
{
	const t_cylinder	*cyl = shape_get_data(shape);
	const bool			hit = cylinder_check_bounds(\
		&params->t1, &cyl->bounds.y_min, &cyl->bounds.y_max, ray);
	const bool			hit2 = cylinder_check_bounds(\
		&params->t2, &cyl->bounds.y_min, &cyl->bounds.y_max, ray);

	cylinder_intersect_cap(ray, shape, i);
	if (hit)
		vector_pushback_intersect(i, params->t1, shape);
	if (hit2)
		vector_pushback_intersect(i, params->t2, shape);
	return (hit || hit2);
}

inline static void	cylinder_intersect_cap(t_ray *ray, t_shape *shape, t_vector *i)
{
	const t_cylinder	*cyl = shape_get_data(shape);
	double				t;

	if (!cyl->capped || is_approx_equal(ray->direction.y, 0, M_EPSILON))
		return ;
	t = (cyl->bounds.y_min - ray->origin.y) / ray->direction.y;
	if (cylinder_is_in_cap(ray, &t))
		vector_pushback_intersect(i, t, shape);
	t = (cyl->bounds.y_max - ray->origin.y) / ray->direction.y;
	if (cylinder_is_in_cap(ray, &t))
		vector_pushback_intersect(i, t, shape);
}
