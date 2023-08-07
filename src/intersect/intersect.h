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
# define MAX_INTERSECTIONS_PER_OBJECT 10

# include "tuple.h"
# include "vector.h"
# include "ray.h"
# include <stdbool.h>
# include "color.h"

typedef struct s_shape	t_shape;
typedef struct s_light	t_light;

typedef struct s_quadratic
{
	double		a;
	double		b;
	double		c;
	double		disc;
	double		t1;
	double		t2;
}				t_quadratic;

typedef struct s_computations
{
	t_tuple		point;
	t_tuple		normal;
	t_tuple		eye;
	t_shape		*shape;
	t_vector	intersections;
	t_vector	shadow_intersections;
	t_tuple		over_point;
	bool		inside;
	bool		is_shadowed;
}				t_computations;

typedef struct s_intersect
{
	double		t;
	t_shape		*obj;
}				t_intersect;

typedef struct s_intersections
{
	size_t		count;
	t_intersect	buffer[MAX_INTERSECTIONS_PER_OBJECT];
}				t_intersections;

void	intersect_world(t_vector *world, t_ray ray, t_vector *intersections);
void	intersect_set_normal(t_computations *comps);
bool	intersect_hit(t_ray *ray, t_computations *comps);
bool	intersect_shadow_hit(t_ray *ray, t_computations *comps, const t_real *distance);
bool	intersect_compute(t_intersect *intersect, t_ray *ray, t_computations *comps);
bool	intersect_is_shadowed(t_vector *world, t_light *light, t_computations *comps);
t_color	intersect_shade_hit(t_vector *world, t_light *light, t_computations *comps);
t_color	intersect_color_at(t_vector *world, t_ray ray, t_computations *comps, t_light *light);
#endif