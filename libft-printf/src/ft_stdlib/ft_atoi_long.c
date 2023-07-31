/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:09:02 by arobu             #+#    #+#             */
/*   Updated: 2023/02/27 14:09:07 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

long	ft_atoi_long(const char *s)
{
	long			sum;
	int				sign;

	sum = 0;
	sign = 1;
	while (ft_isspace3(*s))
		s++;
	if (*s == '-')
		sign = -1;
	if (*s == '+' || *s == '-')
		s++;
	while (*s)
	{
		if (ft_isdigit(*s))
			sum = sum * 10 + (*s - '0');
		else
			break ;
		s++;
	}
	return (sign * sum);
}
