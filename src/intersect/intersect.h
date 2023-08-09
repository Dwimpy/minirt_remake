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
# define MAX_DEPTH 4

# include "tuple.h"
# include "vector.h"
# include "ray.h"
# include <stdbool.h>
# include "color.h"

typedef struct s_scene	t_scene;
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
	t_real		t;
	t_tuple		normal;
	t_tuple		eye;
	t_shape		*shape;
	t_vector	intersections;
	t_vector	shadow_intersections;
	t_vector	ref_index_tracker;
	t_tuple		over_point;
	t_tuple		under_point;
	t_tuple		reflected_dir;
	t_real		n1;
	t_real		n2;
	bool		inside;
	bool		is_shadowed;
}				t_computations;

typedef struct s_intersect
{
	double		t;
	t_shape		*obj;
}				t_intersect;

void		intersect_world(t_scene *world, t_ray *ray);
t_intersect	intersection(t_real t, t_shape *shape);
t_intersect	*intersect_hit(t_vector *intersections);
void		intersect_compute(t_intersect *intersect, t_ray *ray, t_computations *comps);
t_color		intersect_shade_hit(t_scene *world, t_computations *comps);
t_color		intersect_color_at(t_scene *world, t_ray *ray);
bool		intersect_is_shadowed(t_vector *world, t_light *light, t_computations *comps);
t_color		intersect_reflected_color(t_vector *world, t_computations *comps, t_light *light, int depth);
t_color		intersect_refracted_color(t_vector *world, t_computations *comps, t_light *light, int depth);
#endif