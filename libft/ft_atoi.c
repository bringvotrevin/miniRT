/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 00:37:14 by yoojlee           #+#    #+#             */
/*   Updated: 2020/12/31 15:09:46 by yoojlee          ###   ########.fr       */
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

int		ft_atoi(const char *nptr)
{
	int	i;
	int	minus;
	int	num;

	i = 0;
	minus = 1;
	num = 0;
	while (is_space(nptr[i]))
		i++;
	if (nptr[i] == '-')
		minus *= (-1);
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + nptr[i] - '0';
		i++;
	}
	if (minus == -1)
		num *= minus;
	return (num);
}
