/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 02:32:41 by yoojlee           #+#    #+#             */
/*   Updated: 2021/01/02 16:44:25 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	unsigned char	*dst;
	unsigned char	*str;
	size_t			i;

	if (!dest && !src)
		return (0);
	dst = (unsigned char *)dest;
	str = (unsigned char *)src;
	i = 0;
	while (i < count)
	{
		*(dst + i) = *(str + i);
		i++;
	}
	return (dest);
}
