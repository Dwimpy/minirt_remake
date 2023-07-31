/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_approx_equal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:02:12 by arobu             #+#    #+#             */
/*   Updated: 2023/07/30 19:02:12 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

inline bool	is_approx_equal(t_real a, t_real b, t_real epsilon)
{
	return (fabs(a - b) < epsilon);
}