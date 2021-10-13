/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 01:02:39 by yoojlee           #+#    #+#             */
/*   Updated: 2021/01/02 16:58:04 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (i < len && s[start])
	{
		*(ret + i) = *(s + start);
		i++;
		start++;
	}
	*(ret + i) = '\0';
	return (ret);
}
