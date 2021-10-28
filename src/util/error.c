/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:00:23 by dim               #+#    #+#             */
/*   Updated: 2021/10/28 17:04:53 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

void	error(char *msg)
{
	if (msg != NULL)
		ft_putstr(msg);
	else
		ft_putstr(strerror(errno));
	exit(0);
}
