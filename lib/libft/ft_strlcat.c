/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 22:55:19 by yoojlee           #+#    #+#             */
/*   Updated: 2020/12/31 21:47:00 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	srclen;
	size_t	dstlen;

	i = 0;
	srclen = 0;
	dstlen = 0;
	while (src[srclen])
		srclen++;
	while (dst[dstlen])
		dstlen++;
	j = dstlen;
	while (src[i] && (dstlen + i + 1 < size))
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = 0;
	if (dstlen + 1 <= size)
		return (dstlen + srclen);
	return (size + srclen);
}
