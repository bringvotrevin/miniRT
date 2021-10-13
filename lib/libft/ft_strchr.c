/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 18:53:13 by yoojlee           #+#    #+#             */
/*   Updated: 2020/12/31 20:30:57 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *str, int ch)
{
	char	*s;
	char	chr;
	size_t	i;

	s = (char *)str;
	chr = (char)ch;
	i = 0;
	while (s[i])
	{
		if (s[i] == chr)
			return (s + i);
		i++;
	}
	if (chr == 0)
		return (&s[i]);
	return (NULL);
}
