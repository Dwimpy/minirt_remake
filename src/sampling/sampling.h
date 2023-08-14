/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sampling.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 23:46:39 by arobu             #+#    #+#             */
/*   Updated: 2023/08/14 23:46:39 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLING_H
# define SAMPLING_H
# include "rng.h"
# include "stdint.h"

typedef struct s_sample
{
	t_real		x;
	t_real		y;
}			t_sample;

t_sample	*sample_jittered_new(size_t num_samples);
t_real		cubic_filter(t_real sample);
void		cubic_spline_filter(t_sample *samples, const size_t num_samples);
#endif