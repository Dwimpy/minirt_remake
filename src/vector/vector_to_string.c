/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_to_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 20:49:27 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/05 15:00:38 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdio.h>

char	*vector_to_string(t_vector *vector)
{
	size_t	i;
	char	*str;

	str = (char *)malloc(sizeof(char) * (vector->size + 1));
	i = 0;
	while (i < vector->size)
	{
		str[i] = *(char *)vector_at(vector, i);
		i++;
	}
	str[i] = '\0';
	return (str);
}
