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

# include "vec3.h"

typedef struct s_onb
{
	t_vec3		u;
	t_vec3		v;
	t_vec3		w;
}				t_onb;

t_onb	onb_init_from_u(t_vec3 u);
t_onb	onb_init_from_v(t_vec3 v);
t_onb	onb_init_from_w(t_vec3 w);

t_onb	onb_init_from_uv(t_vec3 u, t_vec3 v);
t_onb	onb_init_from_vu(t_vec3 u, t_vec3 v);

t_onb	onb_init_from_uw(t_vec3 u, t_vec3 w);
t_onb	onb_init_from_wu(t_vec3 w, t_vec3 u);

t_onb	onb_init_from_vw(t_vec3 v, t_vec3 w);
t_onb	onb_init_from_wv(t_vec3 w, t_vec3 v);

void	onb_print(t_onb onb);

// Tests
void	onb_tests();
#endif