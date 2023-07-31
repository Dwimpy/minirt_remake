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

#include "libft.h"
#include "vec3.h"

void vec3_print(t_vec3 v) {
	printf("[ %.6f, %.6f, %.6f ]\n", v.x, v.y, v.z);
}