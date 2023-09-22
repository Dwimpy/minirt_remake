/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:25:40 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/22 15:41:06 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <fcntl.h>
# include "vector.h"
# include "tuple.h"
# include "renderer.h"
# include "hooks.h"
# include "libft.h"
# include "sphere.h"
# include "scene.h"


# define LINEBUFFER_MAX 4096

int				line_is_empty(const char *str);
void			is_null(char *str, t_vector vector);
int				valid_value(char *str, int (*comparator)(int c));
int				validator(char **str, int (*comparator)(int c), int n);
t_vector		parse_file(char *str);

void			shut_down_parser(t_vector vector, char *str);
void			set_cam_values(char **str, t_vector *vector, t_camera *camera);
void			test_init(void);
void			free_parser(t_vector vector);
t_tuple			parse_vector(t_vector *vector, int idx, int column);
void			free_double_arr(char **str);

t_material		material_color_apply(t_vector vector, int idx, int column);
t_color			color_apply(t_shape shape, t_vector vector, \
										int idx, int column);
void			position_obj(t_vector *vector, t_shape *obj, \
										int idx, int column);
void			rotation_obj(t_vector *vector, t_shape *obj, \
										int idx, int column);
void			sphere_cube_size(t_vector *vector, t_shape *obj, \
										int idx, int column);
int				is_input_ok(int argc, char **argv);
int				check_parsed_data(t_vector *parsed_data);
#endif
