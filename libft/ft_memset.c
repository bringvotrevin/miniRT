/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 23:54:53 by yoojlee           #+#    #+#             */
/*   Updated: 2020/12/31 16:09:41 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;
	char			*str;

	i = 0;
	ch = (unsigned char)c;
	str = (char *)s;
	while (i < n)
	{
		str[i] = ch;
		i++;
	}
	return (s);
}
