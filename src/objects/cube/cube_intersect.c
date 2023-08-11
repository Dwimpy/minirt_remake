/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_intersect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:45:52 by arobu             #+#    #+#             */
/*   Updated: 2023/08/11 21:45:52 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

inline static void		check_axis_hit(t_real origin, t_real axis, t_real *bounds);

bool	cube_intersect(t_shape *shape, t_ray ray, t_vector *intersections)
{
	t_cube_intersect	bounds;
	double				t_min;
	double				t_max;

	ray = ray_to_object_space(&ray, shape->transform);
	check_axis_hit(ray.origin.x, ray.direction.x, bounds.x);
	check_axis_hit(ray.origin.y, ray.direction.y, bounds.y);
	check_axis_hit(ray.origin.z, ray.direction.z, bounds.z);
	t_min = cube_bounds_get(1, 3, bounds.x[0], bounds.y[0], bounds.z[0]);
	t_max = cube_bounds_get(0, 3, bounds.x[1], bounds.y[1], bounds.z[1]);
	if (t_min > t_max)
		return (false);
	vector_pushback_intersect(intersections, t_min, shape);
	vector_pushback_intersect(intersections, t_max, shape);
	return (true);
}

inline static void	check_axis_hit(t_real origin, t_real axis, t_real *bounds)
{
	t_real	t_min_num;
	t_real	t_max_num;
	t_real	t_max;
	t_real	t_min;
	t_real	tmp;

	t_min_num = (-1 - origin);
	t_max_num = (1 - origin);
	if (fabs(axis) >= M_EPSILON)
	{
		t_min = t_min_num / axis;
		t_max = t_max_num / axis;
	}
	else
	{
		t_max = t_max_num * M_INFINITY;
		t_min = t_min_num * M_INFINITY;
	}
	if (t_min > t_max)
	{
		tmp = t_min;
		t_min = t_max;
		t_max = tmp;
	}
	bounds[0] = t_min;
	bounds[1] = t_max;
}

inline t_real	cube_bounds_get(int min_max, size_t count, ...)
{
	va_list	list;
	double	number;
	double	val;
	size_t	i;

	va_start(list, count);
	i = 0;
	if (min_max == 1)
	{
		number = -M_INFINITY;
		while (i < count)
		{
			val = va_arg(list, double);
			if (val > number)
				number = val;
			i++;
		}
	}
	else if (min_max == 0)
	{
		number = M_INFINITY;
		while (i < count)
		{
			val = va_arg(list, double);
			if (val < number)
				number = val;
			i++;
		}
	}
	return (number);
}