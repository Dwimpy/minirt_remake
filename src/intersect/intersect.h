/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:19:51 by arobu             #+#    #+#             */
/*   Updated: 2023/08/03 19:19:51 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_H
# define INTERSECT_H

#include "shape.h"

typedef struct s_quadratic
{
	double		a;
	double		b;
	double		c;
	double		disc;
}				t_quadratic;

typedef struct s_intersect
{
	size_t		count;
	double		t[2];
	t_shape		*obj;
}				t_intersect;

bool	intersect_hit(t_intersect *intersection, double *t);

#endif