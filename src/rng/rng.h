/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rng.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:36:48 by arobu             #+#    #+#             */
/*   Updated: 2023/07/31 18:36:48 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RNG_H
# define RNG_H
# include <stdlib.h>
# include "vec3.h"
# include <time.h>

double	random_double();
t_vec3	random_vec3();
t_vec3	random_in_unit_sphere();

#endif