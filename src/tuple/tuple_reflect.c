/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_reflect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:42:17 by arobu             #+#    #+#             */
/*   Updated: 2023/08/04 17:42:17 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

inline t_tuple	tuple_reflect(t_tuple v, t_tuple n)
{
	return (tuple_subtract(v, tuple_multiply_s(n, 2.0 * tuple_dot(v, n))));
}
