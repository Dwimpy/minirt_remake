/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_rad_to_deg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:55:43 by arobu             #+#    #+#             */
/*   Updated: 2023/08/02 19:55:43 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

inline double	tf_rad_to_deg(double rad)
{
	return (rad * (180.0 / M_PI));
}

inline double	tf_deg_to_rad(double deg)
{
	return (deg * (M_PI / 180.0));
}