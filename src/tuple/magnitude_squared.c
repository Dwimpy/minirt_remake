/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magnitude_squared.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:52:40 by arobu             #+#    #+#             */
/*   Updated: 2023/07/31 18:52:40 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

inline t_real	tuple_magnitude_squared(t_tuple v)
{
	double	len;

	len = tuple_magnitude(v);
	return (len * len);
}
