/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:59:09 by arobu             #+#    #+#             */
/*   Updated: 2023/09/07 00:09:32 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "hooks.h"
#include "src/parser/parser.h"

void	run_tests(void)
{
//	tuple_tests();
//	matrix_tests();
//	transform_tests();
//	ray_tests();
//	sphere_tests();
//	scene_test_isect_world();
//	scene_test_isect_computations();
//	scene_test_normal_face();
//	scene_test_shade_hit();
//	scene_test_color_at();
//	camera_tests();
//	scene_test_shadows();

}

void run_reflection_tests(void)
{
//	scene_test_reflection_vector();
//	scene_test_reflected_color();
//	scene_test_reflected_shade_hit();
//	scene_test_refraction();
//	scene_test_under_point();
//	scene_test_opaque_surface();
//	scene_test_refracted_color();
}

void run_is_shadow_tests(void)
{
//	intersect_is_shadowed();
//	test_light_intensity_at();
//	test_frac_intensity();
}

void	leaks(void)
{
	system("leaks minirt");
}

int	main(void)
{
	t_scene		scene;
	t_renderer	renderer;
	t_vector	parsed_data;
	t_shape shape;


	run_is_shadow_tests();
	// atexit(leaks);
	parsed_data = test_parser();
	char		**str;
	char		**ptr;
	for (int i = 0; i < parsed_data.size; ++i)
	{
		str = *(char ***)vector_at(&parsed_data, i);
		if (!ft_strncmp(str[0], "R", 2))
			vector_move_to(&parsed_data, i, 0);
		else if (!ft_strncmp(str[0], "C", 1))
			vector_move_to(&parsed_data, i, 1);
		else if (!ft_strncmp(str[0], "L", 2))
			vector_move_to(&parsed_data, i, 2);
		else if (!ft_strncmp(str[0], "A", 2))
			vector_move_to(&parsed_data, i, 3);
	}
	// }
	// // vector_free(&parsed_data);
	for (int i = 0; i < parsed_data.size; ++i)
	{
		str = *(char ***)vector_at(&parsed_data, i);
		ptr = str;
		printf("%s\n", str[0]);
		while (ptr && *ptr)
		{
			free(*ptr);
			ptr++;
		}
		if (str)
			free(str);
	}
	vector_free(&parsed_data);
	// test_init();
	// for (size_t i = 0; i < parsed_data.size; i++)
	// {
	// 	printf("%s\n", (char **)vector_at(&parsed_data, i));
	// }
	// create_scene_from_file(&parsed_data);
// 	renderer_initialize(&renderer, 1920, 1080, true); 
//  	scene = cornell_box();
// 	scene.camera = camera_new(1920, 1080, 50);
// 	camera_view_transform(&scene.camera, \
// 			tuple_new_point(278.0, 278.0, -800), \
// 			tuple_new_point(278.0, 278.0, 0.0));
// 	renderer.args.world = &scene;
// 	mlx_key_hook(renderer.window.mlx, (mlx_keyfunc) key_hooks, &renderer);
// //	scene_render(&scene, &renderer);
// 	renderer_start_threads(&renderer);
// 	window_draw_loop(renderer.window.mlx, &renderer);
// 	tf_free(scene.camera.tf);
// 	vector_free(&renderer.tiles);
// 	free(renderer.samples);
	return (0);
}
//	scene_render(&scene, &scene.camera, &renderer.canvas);
