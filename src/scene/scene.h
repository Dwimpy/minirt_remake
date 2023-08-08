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
# include "light.h"
# include "shape.h"
#include "vector.h"

typedef struct s_scene
{
	t_light		light;
	t_vector	objs;
}				t_scene;

#endif