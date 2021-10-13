/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 19:29:12 by yoojlee           #+#    #+#             */
/*   Updated: 2021/01/02 17:54:41 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t count)
{
	char	*dst;
	char	*str;
	size_t	i;

	if (count == 0 || dest == src)
		return (dest);
	dst = (char *)dest;
	str = (char *)src;
	i = 0;
	if (src < dest)
		while (i < count)
		{
			dst[count - i - 1] = str[count - i - 1];
			i++;
		}
	else
		while (i < count)
		{
			dst[i] = str[i];
			i++;
		}
	return (dest);
}
