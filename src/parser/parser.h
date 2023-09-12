/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:25:40 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/10 17:43:12 by apaghera         ###   ########.fr       */
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

typedef struct t_cy
{
	int				idx;
	float			x;
	float			y;
	float			z;
	float			vect_x;
	float			vect_y;
	float			vect_z;
	float			diameter;
	float			height;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}	t_cy;

typedef struct t_pl
{
	int				idx;
	float			x;
	float			y;
	float			z;
	float			vect_x;
	float			vect_y;
	float			vect_z;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}	t_pl;

typedef struct t_sp
{
	int				idx;
	float			x;
	float			y;
	float			z;
	float			diameter;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}	t_sp;

typedef struct t_parse_light
{
	int				idx;
	float			x;
	float			y;
	float			z;
	float			ratio;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}	t_parse_light;

typedef struct t_parse_camera
{
	int				idx;
	float			vx;
	float			vy;
	float			vz;
	float			ox;
	float			oy;
	float			oz;
	unsigned int	fov;
}	t_parse_camera;

typedef struct t_ambient
{
	int				idx;
	float			ambient_ratio;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;	
}	t_ambient;

typedef struct t_res
{
	int		idx;
	int		high;
	int		width;
}	t_res;

typedef struct s_data
{
	t_res			*resolution;
	t_ambient		*ambient;
	t_parse_camera	*camera;
	t_parse_light	*light;
	t_sp			*sphere;
	t_pl			*plane;
	t_cy			*cylinder;
}	t_data;

int				line_is_empty(const char *str);
t_vector		test_parser(void);
t_ambient		*initialize_ambient(void);
t_res			*initiliaze_res(void);
t_data			*initialize_data(void);
t_cy			*initialize_cy(void);
t_pl			*initialize_pl(void);
t_sp			*initialize_sp(void);
t_parse_light	*initialize_light(void);
t_parse_camera	*initialize_camera(void);
void			test_init(void);
void			free_parser(t_vector vector);
t_tuple			parse_vector(t_vector *vector, int idx, int column);
void			free_double_arr(char **str);
t_material		material_color_apply(t_vector vector, int idx, int column);
t_color			color_apply(t_shape shape, t_vector vector, int idx, int column);

#endif
