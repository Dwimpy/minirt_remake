/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:17:09 by arobu             #+#    #+#             */
/*   Updated: 2023/08/02 18:17:09 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H
# include "matrix.h"
# include "math.h"

typedef struct s_transform
{
	t_matrix	tf;
	t_matrix	inv_tf;
	t_matrix	tf_transpose;
	t_matrix	inv_tf_transpose;
}				t_transform;

// Rotate -> Scale -> Translate for chained transformations

t_transform	tf_new(void);
t_transform	tf_transform(t_transform rotate, t_transform scale, t_transform translate);
t_transform	tf_translate(double x, double y, double z);
t_transform	tf_scale(double x, double y, double z);
t_transform	tf_shear(double xy, double xz, double yx, double yz, double zx, double zy);
t_transform	tf_rotate(double deg_x, double deg_y, double deg_z);
t_transform	tf_rotate_x(double degrees);
t_transform	tf_rotate_y(double degrees);
t_transform	tf_rotate_z(double degrees);
t_transform	tf_shape_to_orientation(t_tuple to);

double		tf_rad_to_deg(double deg);
double		tf_deg_to_rad(double rad);
void		transform_tests();
void		tf_free(t_transform tf);

#endif