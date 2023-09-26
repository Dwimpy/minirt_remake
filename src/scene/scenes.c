/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:21:19 by arobu             #+#    #+#             */
/*   Updated: 2023/09/19 12:08:36 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "cube.h"
#include "../light/light.h"
#include "scene.h"
#include "sphere.h"
#include "renderer.h"

t_scene	def_scene(t_renderer *renderer)
{
	t_scene		world;

	renderer_initialize(renderer, 1920, 1080, true);
	world.light = light_rect_new((t_rect_light_params)
		{
			tuple_new_point(0, 0, 0),
			color_multiply_s(color_new(0.94, 0.94, 0.94), 1),
			tuple_new_vector(0, 1, 0),
			coord_new(32, 32), 2
		});
	world.objs = vector_init(10, sizeof(t_shape));
	world.comps.ref_index_tracker = vector_init(10, sizeof(t_shape **));
	world.camera = camera_new(renderer->window.width, \
		renderer->window.height, 90);
	camera_view_transform(&world.camera, \
		tuple_new_point(0.0, 0.0, -1.0), tuple_new_point(0.0, 0.0, 0.0));
	renderer->args.world = &world;
	return (world);
}
