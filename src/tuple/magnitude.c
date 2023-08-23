/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magnitude.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:53:27 by arobu             #+#    #+#             */
/*   Updated: 2023/07/30 18:53:27 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"
#include <math.h>

inline t_real	tuple_magnitude(t_tuple v)
{
	return (sqrt(tuple_dot(v, v)));
}
