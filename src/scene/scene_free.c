/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:03:25 by arobu             #+#    #+#             */
/*   Updated: 2023/08/22 22:09:07 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	free_scene(t_scene *scene)
{
	t_vector_iterator	it;
	t_shape				*shape;

	vector_iterator_begin(&it, &scene->objs);
	while (!it.end(&it))
	{
		shape = it.get(&it);
		shape_free(shape);
		it.next(&it);
	}
	tf_free(scene->camera.tf);
	vector_free(&scene->comps.ref_index_tracker);
}
