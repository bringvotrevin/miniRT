/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 23:16:43 by yoojlee           #+#    #+#             */
/*   Updated: 2020/12/31 16:21:48 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*str;

	i = 0;
	dst = (unsigned char *)dest;
	str = (unsigned char *)src;
	while (i < n)
	{
		dst[i] = str[i];
		if (str[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
