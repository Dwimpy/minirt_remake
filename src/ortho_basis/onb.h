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
# include "tuple.h"

typedef struct s_onb
{
	t_tuple		forward;
	t_tuple		up;
	t_tuple		left;
}				t_onb;

t_onb	onb_create_left(t_tuple normal);

#endif
