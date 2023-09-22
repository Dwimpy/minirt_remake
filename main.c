/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:59:09 by arobu             #+#    #+#             */
/*   Updated: 2023/09/22 10:09:29 by apaghera         ###   ########.fr       */
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
	if (str[3])
		shut_down_parser(*vector, "Invalid ambient");
	ambient = ft_atof(str[1]);
	color = parse_vector(vector, 2, 3);
	str = *(char ***)vector_at(vector, 2);
	if (str[4])
		shut_down_parser(*vector, "Invalid light");
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

int	mandatory_identifier(char *str)
{
	if (!ft_strncmp(str, "#", 2))
		return (1);
	else if (!ft_strncmp(str, "R", 2))
		return (1);
	else if (!ft_strncmp(str, "L", 2))
		return (1);
	else if (!ft_strncmp(str, "A", 2))
		return (1);
	else if (!ft_strncmp(str, "C", 2))
		return (1);
	else
		return (0);
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
		else if (!ft_strncmp(str[0], "cu", 3))
				create_cube(vector, scene, i);
		else if	(!ft_strncmp(str[0], "cy", 3))
				create_cylinder(vector, scene, i);
		else if	(!ft_strncmp(str[0], "pl", 3))
			create_plane(vector, scene, i);
		else
		{
			if (!mandatory_identifier(str[0]))
				shut_down_parser(vector, "Identifier not found");
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_scene		scene;
	t_vector	parsed_data;
	int			i;
	char		**str;
	int			j;

	i = 0;
	j = -1;
	//run_is_shadow_tests();
	// atexit(leaks);
	if (argc != 2)
	{
		printf("Invalid format\n");
		return (0);
	}
	parsed_data = test_parser(argv[1]);
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
 	tf_free(scene.camera.tf);
	free(scene.light.data);
	t_shape *shape;
	while (++j < scene.objs.size)
	{
		shape = (t_shape *)vector_at(&scene.objs, j);
		shape_free(shape);
	}
	vector_free(&scene.comps.ref_index_tracker);
	vector_free(&scene.objs);
	return (0);
}
//	scene_render(&scene, &scene.camera, &renderer.canvas);
