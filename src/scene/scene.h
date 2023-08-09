/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 23:02:43 by arobu             #+#    #+#             */
/*   Updated: 2023/08/03 23:02:43 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H
# include "intersect.h"
# include "light.h"
# include "vector.h"

typedef struct s_scene
{
	t_light			light;
	t_vector		objs;
	t_vector		intersections;
	t_computations	comps;
}				t_scene;

t_scene	scene_default(void);
void	scene_test_isect_world(void);
void	scene_test_isect_computations(void);
void	scene_test_normal_face(void);
void	scene_test_shade_hit(void);
void	scene_test_color_at(void);

#endif