/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:59:09 by arobu             #+#    #+#             */
/*   Updated: 2023/09/19 13:47:33 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "hooks.h"
#include "src/parser/parser.h"
#include "libft.h"
#include "sphere.h"
#include "cube.h"
#include "plane.h"
#include "cylinder.h"

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

t_scene	give_light(t_vector *vector)
{
	t_scene	world;
	t_tuple	color;
	double	ambient;
	char	**str;

	str = *(char ***)vector_at(vector, 3);
	ambient = ft_atof(str[1]);
	color = parse_vector(vector, 2, 3);
	world.light = light_rect_new((t_rect_light_params)
	{
		parse_vector(vector, 2, 1),  // from
		color_multiply_s(color, (1.0 / 255.0)),  //rgb + ratio
		tuple_new_point(0, 1, 0),
		coord_new(32, 32), 2 // size of rectangle "quality of light"
	}); // i need only this for the light create a new function
//	world.light = light_point_new(tuple_new_point(0, 25, -120), color_new(0.2, 0.2, 0.2));
	world.objs = vector_init(10, sizeof(t_shape));
	world.comps.ref_index_tracker = vector_init(10, sizeof(t_shape **));
	return (world);
}

void	maker_obj(t_vector vector, t_scene *scene)
{
	int	i;
	char **str;

	i = 0;
	while(i < vector.size)
	{
		str = *(char ***)vector_at(&vector, i);
		if (!ft_strncmp(str[0], "sp", 3))
			create_sphere(vector, scene, i);
		if (!ft_strncmp(str[0], "cu", 3))
				create_cube(vector, scene, i);
		if	(!ft_strncmp(str[0], "cy", 3))
			create_cylinder(vector, scene, i);
		if	(!ft_strncmp(str[0], "pl", 3))
			create_plane(vector, scene, i);
		i++;
	}
}

int	main(void)
{
	t_scene		scene;
	t_renderer	renderer;
	t_vector	parsed_data;
	int			i;
	char		**str;

	i = 0;
	//run_is_shadow_tests();
	// atexit(leaks);
	parsed_data = test_parser();
	scene = give_light(&parsed_data);
	maker_obj(parsed_data, &scene);
	create_scene_from_file(&parsed_data, &scene);
	free_parser(parsed_data);
// 	renderer_initialize(&renderer, 1920, 1080, true); 
 	// scene = cornell_box();
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
