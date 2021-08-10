/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 22:48:05 by yoojlee           #+#    #+#             */
/*   Updated: 2021/01/01 23:18:04 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			ch;
	unsigned int	num;

	if (n < 0)
	{
		write(fd, "-", 1);
		num = n * -1;
	}
	else
		num = n;
	if (num > 9)
		ft_putnbr_fd(num / 10, fd);
	ch = num % 10 + '0';
	write(fd, &ch, 1);
}
