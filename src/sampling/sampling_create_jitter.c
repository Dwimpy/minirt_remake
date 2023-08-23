/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sampling_jitter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 00:11:16 by arobu             #+#    #+#             */
/*   Updated: 2023/08/23 16:51:02 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sampling.h"

static void	generate_samples(size_t sqrt_samples, t_sample *samples);

t_sample	*sample_jittered_new(size_t num_samples)
{
	t_sample	*samples;
	size_t		sqrt_samples;

	samples = ft_calloc(num_samples, sizeof(t_sample));
	if (!samples)
	{
		printf("Failed allocating memory for samples, exiting\n");
		exit (1);
	}
	sqrt_samples = (size_t)sqrt((t_real)num_samples);
	generate_samples(sqrt_samples, samples);
	return (samples);
}

static void	generate_samples(size_t sqrt_samples, t_sample *samples)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < sqrt_samples)
	{
		j = 0;
		while (j < sqrt_samples)
		{
			samples[i * sqrt_samples + j].x = \
				((t_real)i + random_double()) / (t_real)sqrt_samples;
			samples[i * sqrt_samples + j].y = \
				((t_real)j + random_double()) / (t_real)sqrt_samples;
			++j;
		}
		++i;
	}
}
