/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 05:07:52 by dim               #+#    #+#             */
/*   Updated: 2021/10/18 16:35:08 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_space(const char c)
{
	if (c == '\f' || c == '\n' || c == '\r' ||
			c == '\t' || c == '\v' || c == ' ')
		return (1);
	return (0);
}

double		ft_atof(const char *str)
{
	double		num;
	double		sign;
	double		mantissa;

	num = 0.0f;
	sign = 1.0f;
	mantissa = 0.1f;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1.0f;
	while (ft_isdigit(*str))
	{
		num = 10 * num + (double)(*str - '0');
		str++;
	}
	if (*str++ != '.')
		return (num * sign);
	while (ft_isdigit(*str))
	{
		num = num + mantissa * (double)(*str - '0');
		mantissa = mantissa * 0.1;
		str++;
	}
	num = num * sign;
	return (num);
}
