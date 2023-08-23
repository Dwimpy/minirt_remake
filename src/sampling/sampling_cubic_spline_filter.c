/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sampling_cubic_spline_filter.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 00:20:19 by arobu             #+#    #+#             */
/*   Updated: 2023/08/15 00:20:19 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sampling.h"

void	cubic_spline_filter(t_sample *samples, const size_t num_samples)
{
	size_t	i;

	i = 0;
	while (i < num_samples)
	{
		samples[i].x = cubic_filter(samples[i].x);
		samples[i].y = cubic_filter(samples[i].y);
		++i;
	}
}
