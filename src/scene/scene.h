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
	t_computations	comps;
}				t_scene;

t_scene	scene_default(void);
void	scene_render(t_scene *world, t_renderer *renderer);
t_scene	cornell_box(void);
#endif