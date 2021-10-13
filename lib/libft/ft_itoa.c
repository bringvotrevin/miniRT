/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 02:47:58 by yoojlee           #+#    #+#             */
/*   Updated: 2021/01/02 18:47:16 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		cnt_digit(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*mem_alloc(int count, int minus)
{
	char	*ch;

	if (minus == -1)
		ch = (char *)malloc(sizeof(char) * (count + 2));
	else if (minus == 1)
		ch = (char *)malloc(sizeof(char) * (count + 1));
	else
		ch = NULL;
	return (ch);
}

char	*put_num(char *ch, long n, int count, int minus)
{
	int	i;

	if (minus == -1)
	{
		ch[0] = '-';
		i = count + 1;
	}
	else
		i = count;
	ch[i] = '\0';
	if (n == 0)
		ch[0] = '0';
	while (n > 0)
	{
		ch[--i] = (n % 10) + 48;
		n = n / 10;
	}
	if (i != 0 && i != 1)
		return (0);
	return (ch);
}

char	*ft_itoa(int num)
{
	int		count;
	char	*ch;
	int		minus;
	long	n;

	n = (long)num;
	count = 0;
	minus = 1;
	if (n < 0)
	{
		minus = -1;
		n *= -1;
	}
	count = cnt_digit(n);
	if (count < 0)
		return (0);
	ch = mem_alloc(count, minus);
	if (ch == 0)
		return (0);
	if (!put_num(ch, n, count, minus))
		return (0);
	return (ch);
}
