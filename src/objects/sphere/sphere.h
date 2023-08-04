/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:14:40 by arobu             #+#    #+#             */
/*   Updated: 2023/08/01 15:14:40 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H
#include "intersect.h"
# define SPHERE_MEM_ALLOCATION_FAILED "Sphere memory allocation failed. Exiting.\n"

# include "shape.h"


typedef struct s_sphere
{
	t_tuple 	origin;
	t_real		radius;
	t_color		color;
} 				t_sphere;

t_shape 	shape_new_sphere(t_tuple origin, t_real radius, t_color color);
void		sphere_print(t_shape *shape);
void		*get_sphere_data(t_shape *shape);
bool		sphere_intersect(t_shape *shape, t_ray ray, t_intersections *intersections);
t_color		get_sphere_color(t_shape *shape);
t_tuple		sphere_normal_at(t_shape *shape, t_tuple isec_point);
bool		sphere_shadow_hit(t_shape *shape, t_ray ray, t_intersections *intersections);

#endif