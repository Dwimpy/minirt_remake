/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:19:51 by arobu             #+#    #+#             */
/*   Updated: 2023/08/22 16:04:21 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_H
# define INTERSECT_H
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
	t_real		frac_intensity;
}				t_computations;

typedef struct s_refracted_params
{
	t_real	n_ratio;
	t_real	cosi;
	t_real	sin2t;
	t_real	cos_t;
	t_tuple	direction;
	t_ray	refracted_ray;
	t_color	color;
}				t_refracted_params;

typedef struct s_intersect
{
	double		t;
	t_shape		*obj;
}				t_intersect;

typedef struct s_thread_isect
{
	t_vector		intersections;
	t_vector		shadow_isect;
	t_computations	comps;
}				t_thread_isect;

t_intersect	*intersect_hit(t_vector *intersections);
void		intersect_compute(\
	t_intersect *i, t_ray *ray, t_computations *comps, t_vector *isect);
void		intersect_world_threads(\
	t_scene *world, t_thread_isect *intersections, t_ray *ray_thread);
void		intersect_shadow_world_threads(\
	t_scene *world, t_thread_isect *intersections, t_ray *ray_thread);
bool		intersect_shadow_hit_threads(\
	t_scene *world, t_tuple *light_pos, t_tuple *point, t_thread_isect *isect);
t_color		intersect_shade_hit_threads(\
	t_scene *world, t_computations *comps, int depth, t_thread_isect *isect);
t_color		intersect_color_at_threads(\
	t_scene *world, t_ray *ray, int depth, t_thread_isect *intersections);
t_color		intersect_reflected_color_threads(\
	t_scene *world, t_thread_isect *isect, t_computations *comps, int depth);
t_color		intersect_refracted_color_threads(\
	t_scene *world, t_thread_isect *isect, t_computations *comps, int depth);

#endif
