/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_to_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 20:49:27 by apaghera          #+#    #+#             */
/*   Updated: 2023/09/03 21:18:30 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

char		*vector_to_string(t_vector *vector)
{
	size_t	i;
	char	*str;

	str = ft_calloc(vector->size, sizeof(char));
	i = 0;
	while (i < vector->size)
	{
		str[i] = *(char *)vector_at(vector, i);
		i++;
	}
	str[i] = '\0';
	return (str);
}