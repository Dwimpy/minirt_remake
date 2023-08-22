/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 23:02:43 by arobu             #+#    #+#             */
/*   Updated: 2023/08/22 17:37:21 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H
# include "camera.h"
# include "color.h"
# include "intersect.h"
# include "../light/light.h"
# include "vector.h"
# include "image.h"
# include <pthread.h>

typedef struct s_renderer	t_renderer;
typedef struct s_scene
{
	t_light			light;
	t_camera		camera;
	t_vector		objs;
	t_vector		intersections;
	t_vector		shadow_intersections;
	t_computations	comps;
}				t_scene;

t_scene	scene_default(void);
void	scene_render(t_scene *world, t_renderer *renderer);
void	scene_test_refraction(void);
void	scene_test_isect_world(void);
void	scene_test_isect_computations(void);
void	scene_test_normal_face(void);
void	scene_test_shade_hit(void);
void	scene_test_color_at(void);
void	scene_test_shadows(void);
void	scene_test_reflection_vector(void);
void	scene_test_reflected_color(void);
void	scene_test_reflected_shade_hit(void);
void	scene_test_under_point(void);
void	scene_test_opaque_surface(void);
void	scene_test_refracted_color(void);
void	intersect_is_shadowed(void);
void	test_light_intensity_at(void);
void	test_frac_intensity(void);
t_scene	cornell_box(void);
#endif