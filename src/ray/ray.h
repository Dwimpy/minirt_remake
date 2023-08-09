/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:32:22 by arobu             #+#    #+#             */
/*   Updated: 2023/07/30 23:32:22 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "transform.h"
# include "tuple.h"

typedef struct s_ray
{
	t_tuple		origin;
	t_tuple		direction;
}				t_ray;

t_ray	ray_new(t_tuple origin, t_tuple direction);
t_tuple	ray_at(t_ray ray, t_real t);
t_ray	ray_to_object_space(t_ray *ray, t_transform tf);
t_ray	ray_to_world_space(t_ray *ray, t_transform tf);
void	ray_set(t_ray *ray, t_tuple origin, t_tuple direction);
void	ray_tests(void);
#endif