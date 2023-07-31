/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:24:00 by arobu             #+#    #+#             */
/*   Updated: 2023/02/25 13:48:44 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static void	treat_dot(const char **str, int *e, \
					int *res_sign, double *result);
static void	treat_exp_not(const char **str, int *sign);
static void	do_calculation(int *e, double *result);

double	ft_atof(const char *str)
{
	double	result;
	int		e_sign;
	int		e;
	int		i;
	int		res_sign;

	result = 0.0;
	e = 0;
	res_sign = 1;
	treat_dot(&str, &e, &res_sign, &result);
	treat_exp_not(&str, &e_sign);
	i = 0;
	while (ft_isdigit(*str))
	{
		i = i * 10 + (*str - '0');
		str++;
	}
	e += i * e_sign;
	do_calculation(&e, &result);
	return (result * (double)res_sign);
}

static void	do_calculation(int *e, double *result)
{
	while (*e > 0)
	{
		*result *= 10.0;
		(*e)--;
	}
	while (*e < 0)
	{
		*result *= 0.1;
		(*e)++;
	}
}

static void	treat_dot(const char **str, int *e, int *res_sign, double *result)
{
	while (ft_isspace3(**str))
		(*str)++;
	if (**str == '-')
	{
		(*str)++;
		*res_sign = -1;
	}
	else if (**str == '+')
		(*str)++;
	while (**str && ft_isdigit(**str))
	{
		*result = *result * 10.0 + (**str - '0');
		(*str)++;
	}
	if (**str == '.')
	{
		(*str)++;
		while (**str && ft_isdigit(**str))
		{
			*result = *result * 10.0 + (**str - '0');
			*e -= 1;
			(*str)++;
		}
	}
}

static void	treat_exp_not(const char **str, int *sign)
{
	if (**str == 'e' || **str == 'E')
	{
		*sign = 1;
		(*str)++;
		if (**str == '+')
			(*str)++;
		else if (**str == '-')
		{
			*sign = -1;
			(*str)++;
		}
	}
}
