/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:19:51 by arobu             #+#    #+#             */
/*   Updated: 2023/08/03 19:19:51 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_H
# define INTERSECT_H
#include "tuple.h"
# define MAX_INTERSECTIONS_PER_OBJECT 10
# include "vector.h"
# include "ray.h"
typedef struct s_shape	t_shape;

typedef struct s_quadratic
{
	double		a;
	double		b;
	double		c;
	double		disc;
	double		t1;
	double		t2;
}				t_quadratic;

typedef struct s_intersect
{
	double		t;
	t_shape		*obj;
}				t_intersect;

typedef struct s_intersections
{
	size_t		count;
	t_intersect buffer[MAX_INTERSECTIONS_PER_OBJECT];
}				t_intersections;

void	initialize_intersections(t_intersections *intersections);
void	intersect_world(t_vector *world, t_ray ray, t_intersections *isect_ptr, t_intersections *intersections);
bool intersect_hit(t_intersections *intersections, t_ray *ray, t_tuple *isec_point, t_tuple *normal, t_shape *shape);

#endif