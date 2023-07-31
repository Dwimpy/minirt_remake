/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 00:34:48 by arobu             #+#    #+#             */
/*   Updated: 2023/04/14 00:37:02 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, char *src, size_t len)
{
	char	*dst_ptr;
	size_t	i;

	i = 0;
	dst_ptr = dst;
	if (!dst)
		return (NULL);
	while (*dst != '\0')
		dst++;
	while (*src != '\0' && i < len)
	{
		*dst++ = *src++;
		i++;
	}
	*dst = '\0';
	return (dst_ptr);
}
