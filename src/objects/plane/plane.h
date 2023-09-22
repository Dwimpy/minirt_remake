/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:00:13 by arobu             #+#    #+#             */
/*   Updated: 2023/09/11 14:49:06 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H
# define PLANE_MEM_ALLOCATION_FAILED\
			"Plane memory allocation failed. Exiting.\n"
# include "shape.h"
# include "tuple.h"

typedef struct s_plane
{
	t_tuple		origin;
	t_tuple		normal;
}				t_plane;

t_shape		shape_new_plane(void);
void		plane_print(t_shape *shape);
bool		plane_intersect(t_shape *shape, t_ray ray, t_vector *intersections);
t_tuple		plane_normal_at(t_shape *shape, t_tuple isec_point);
void		create_plane(t_vector vector, t_scene *scene, size_t idx);

#endif