/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 03:52:34 by yoojlee           #+#    #+#             */
/*   Updated: 2021/01/02 05:31:34 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		remove_front(char const *s1, char const *set)
{
	int		i;
	int		j;

	i = 0;
	while (s1[i])
	{
		j = -1;
		while (set[++j])
		{
			if (s1[i] != set[j])
				continue ;
			break ;
		}
		if (set[j] == '\0')
			return (i);
		i++;
	}
	return (i);
}

int		remove_back(char const *s1, char const *set)
{
	int		i;
	int		j;

	i = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		j = -1;
		while (set[++j])
		{
			if (s1[i] != set[j])
				continue ;
			break ;
		}
		if (set[j] == '\0')
			return (i);
		i--;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	start;
	size_t	end;
	size_t	i;

	i = 0;
	start = remove_front(s1, set);
	if (start == ft_strlen(s1))
		return (ft_strdup(""));
	end = remove_back(s1, set);
	if (!(ret = (char *)malloc(sizeof(char) * (end - start + 2))))
		return (0);
	while (start <= end && s1[start])
	{
		*(ret + i) = s1[start];
		start++;
		i++;
	}
	*(ret + i) = '\0';
	return (ret);
}
