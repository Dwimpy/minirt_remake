/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 23:02:43 by arobu             #+#    #+#             */
/*   Updated: 2023/09/21 11:19:02 by apaghera         ###   ########.fr       */
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
t_scene	def_scene(t_renderer *renderer);
t_scene	scene_from_file(t_renderer *renderer, char *filepath);
t_scene	scene_give_light(t_vector *vector);
int		view_from_to_valid(char *str, t_vector vector);
void	scene_object_maker(t_vector vector, t_scene *scene);
void	scene_free(t_scene *scene);
int		validator_special(char **str, int (*comparator)(int c), int n);
#endif