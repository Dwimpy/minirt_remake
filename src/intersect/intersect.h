/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:19:51 by arobu             #+#    #+#             */
/*   Updated: 2023/08/18 15:08:39 by arobu            ###   ########.fr       */
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
	t_real		a;
	t_real		b;
	t_real		c;
	t_real		disc;
	t_real		t1;
	t_real		t2;
}				t_quadratic;

typedef struct s_computations
{
	t_tuple		point;
	t_real		t;
	t_tuple		normal;
	t_tuple		eye;
	t_shape		*shape;
	t_vector	ref_index_tracker;
	t_tuple		over_point;
	t_tuple		under_point;
	t_tuple		reflected_dir;
	t_real		n1;
	t_real		n2;
	bool		inside;
	bool		is_shadowed;
	t_real		frac_intensity;
}				t_computations;

typedef struct s_intersect
{
	double		t;
	t_shape		*obj;
}				t_intersect;

void		intersect_world(t_scene *world, t_ray *ray);
t_vector	intersect_world_test(t_scene *world, t_ray *ray);
void		intersect_shadow_world(t_scene *world, t_ray *ray);
t_intersect	intersection(t_real t, t_shape *shape);
t_intersect	*intersect_hit(t_vector *intersections);
void		intersect_compute(t_intersect *i, t_ray *ray, t_computations *comps, t_vector *intersections);
bool		intersect_shadow_hit(t_scene *world, t_tuple *light_pos, t_tuple *point);
t_color		intersect_shade_hit(t_scene *world, t_computations *comps, int depth);
t_color		intersect_color_at(t_scene *world, t_ray *ray, int depth);
t_color		intersect_reflected_color(t_scene *world, t_computations *comps, int depth);
t_color		intersect_refracted_color(t_scene *world, t_computations *comps, int depth);

#endif