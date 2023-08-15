/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sampling_cubic_filter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 00:24:33 by arobu             #+#    #+#             */
/*   Updated: 2023/08/15 00:24:33 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sampling.h"
#include <math.h>

static inline t_real	cubic_filter_solver(t_real sample);

inline t_real	cubic_filter(t_real sample)
{
	if (sample < 1.0 / 24.0)
		return (pow(24 * sample, 0.25) - 2.0);
	else if (sample < 0.5)
		return (cubic_filter_solver(24.0 * (sample - 1.0 / 24.0) / 11.0) - 1.0);
	else if (sample < 23.0 / 24.0)
		return (1.0 - cubic_filter_solver(24.0 * (23.0 / 24.0 - sample) / 11.0));
	else
		return (2 - pow(24.0 * (1.0 - sample), 0.25));
}

static inline t_real	cubic_filter_solver(t_real sample)
{
	t_real	u;
	size_t	i;

	u = sample;
	i = 0;
	while (i < 5)
	{
		u = (11.0 * sample + u * u * (6.0 + u * (8.0 - 9.0 * u))) / \
			(4.0 + 12.0 * u * (1.0 + u * (1.0 - u)));
		++i;
	}
	return (u);
}