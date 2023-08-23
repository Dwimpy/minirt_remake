/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:36:49 by arobu             #+#    #+#             */
/*   Updated: 2023/07/30 18:36:49 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

inline void	tuple_print(t_tuple v)
{
	printf("[ %.6f, %.6f, %.6f, %.6f]\n", v.x, v.y, v.z, v.w);
}

inline t_tuple	tuple_print_ret(t_tuple v)
{
	printf("[ %.6f, %.6f, %.6f, %.6f]\n", v.x, v.y, v.z, v.w);
	fflush(stdout);
	return (v);
}
