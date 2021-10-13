/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 22:21:49 by yoojlee           #+#    #+#             */
/*   Updated: 2021/01/02 05:31:41 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	while (little[i] && big[i] && i < len)
	{
		if (big[i] != little[i])
			return (0);
		i++;
	}
	if (little[i] != 0)
		return (0);
	else
		return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*little == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (big[i] == little[j])
		{
			if (check(big + i, little, len - i))
				return ((char *)big + i);
		}
		i++;
	}
	return (0);
}
