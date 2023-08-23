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
	t_matrix	translation;
	t_matrix	rotation;
	t_matrix	scaling;
	t_matrix	tf;
	t_matrix	inv_tf;
	t_matrix	inv_tf_transpose;
}				t_transform;

// Rotate -> Scale -> Translate for chained transformations

t_transform	tf_new(void);
void		tf_compute(t_transform *transform);
void		tf_reset(t_transform *tf);
void		tf_translate(t_transform *tf, double x, double y, double z);
void		tf_scale(t_transform *tf, double x, double y, double z);
void		tf_rotate(\
	t_transform *tf, double deg_x, double deg_y, double deg_z);
void		tf_rotate_x(t_transform *tf, double degrees);
void		tf_rotate_y(t_transform *tf, double degrees);
void		tf_rotate_z(t_transform *tf, double degrees);
t_transform	tf_shape_to_orientation(t_tuple to);
double		tf_rad_to_deg(double deg);
double		tf_deg_to_rad(double rad);
void		tf_free(t_transform tf);

#endif
