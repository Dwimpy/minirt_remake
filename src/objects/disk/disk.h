/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 18:46:22 by arobu             #+#    #+#             */
/*   Updated: 2023/08/12 18:46:22 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISK_H
# define DISK_H
# define DISK_MEM_ALLOCATION_FAILED\
			"Disk memory allocation failed. Exiting.\n"
# include "tuple.h"
# include "intersect.h"
# include "vector.h"
# include "shape.h"
# include <stdarg.h>

typedef struct s_disk
{
	t_tuple		origin;
	t_tuple		normal;
}				t_disk;

t_shape		shape_new_disk(void);
void		disk_print(t_shape *shape);
bool		disk_intersect(t_shape *shape, t_ray ray, t_vector *intersections);
t_tuple		disk_normal_at(t_shape *shape, t_tuple isec_point);

#endif