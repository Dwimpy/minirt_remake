/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:14:40 by arobu             #+#    #+#             */
/*   Updated: 2023/09/09 15:50:45 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H
# define SPHERE_MEM_ALLOCATION_FAILED\
			"Sphere memory allocation failed. Exiting.\n"
# include "tuple.h"
# include "intersect.h"
# include "vector.h"
# include "shape.h"

typedef struct s_sphere
{
	t_tuple		origin;
	t_real		radius;
}				t_sphere;

t_shape		shape_new_sphere(void);
void		sphere_print(t_shape *shape);
bool		sphere_intersect(\
	t_shape *shape, t_ray ray, t_vector *intersections);
t_tuple		sphere_normal_at(t_shape *shape, t_tuple isec_point);
void		create_sphere(t_scene *scene);

#endif
