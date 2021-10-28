/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 21:51:51 by yoojlee           #+#    #+#             */
/*   Updated: 2021/10/28 18:54:03 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	idx;

	idx = 0;
	while (s1[idx] || s2[idx])
	{
		if (s1[idx] > s2[idx])
			return (s1[idx] - s2[idx]);
		else if (s1[idx] < s2[idx])
			return (s1[idx] - s2[idx]);
		idx++;
	}
	return (0);
}
