/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 00:34:11 by arobu             #+#    #+#             */
/*   Updated: 2023/04/14 00:36:51 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, char *src, size_t len)
{
	char	*dst_ptr;
	size_t	i;

	dst_ptr = dst;
	i = 0;
	if (!dst)
		return (NULL);
	while (*src != '\0' && i < len)
	{
		*dst++ = *src++;
		i++;
	}
	*dst = '\0';
	return (dst_ptr);
}
