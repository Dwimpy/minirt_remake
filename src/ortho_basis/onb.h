/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onb.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:59:56 by arobu             #+#    #+#             */
/*   Updated: 2023/07/31 18:59:56 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ONB_H
# define ONB_H
# define ONB_EPSILON 0.01

# include "tuple.h"

typedef struct s_onb
{
	t_tuple		u;
	t_tuple		v;
	t_tuple		w;
}				t_onb;

t_onb	onb_init_from_u(t_tuple u);
t_onb	onb_init_from_v(t_tuple v);
t_onb	onb_init_from_w(t_tuple w);

t_onb	onb_init_from_uv(t_tuple u, t_tuple v);
t_onb	onb_init_from_vu(t_tuple u, t_tuple v);

t_onb	onb_init_from_uw(t_tuple u, t_tuple w);
t_onb	onb_init_from_wu(t_tuple w, t_tuple u);

t_onb	onb_init_from_vw(t_tuple v, t_tuple w);
t_onb	onb_init_from_wv(t_tuple w, t_tuple v);

void	onb_print(t_onb onb);

// Tests
void	onb_tests();
#endif