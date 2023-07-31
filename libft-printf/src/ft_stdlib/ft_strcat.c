/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:11:49 by arobu             #+#    #+#             */
/*   Updated: 2023/04/05 02:25:21 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, char *src)
{
	char	*dst_ptr;

	dst_ptr = dst;
	if (!dst)
		return (NULL);
	while (*dst != '\0')
		dst++;
	while (*src != '\0')
		*dst++ = *src++;
	*dst = '\0';
	return (dst_ptr);
}
