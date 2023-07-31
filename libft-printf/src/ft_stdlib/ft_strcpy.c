/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:50:10 by arobu             #+#    #+#             */
/*   Updated: 2023/04/01 17:07:55 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, char *src)
{
	char	*dst_ptr;

	dst_ptr = dst;
	if (!dst)
		return (NULL);
	while (*src != '\0')
		*dst++ = *src++;
	*dst = '\0';
	return (dst_ptr);
}
