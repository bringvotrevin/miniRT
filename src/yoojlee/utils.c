/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:27:26 by yoojlee           #+#    #+#             */
/*   Updated: 2021/10/21 17:48:28 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"
#include <stdio.h>

void	swap_double(double *a, double *b)
{
	double	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

double	check_max(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}


void	print_vec(t_vec vec, char *str)
{
	printf("%s : (%lf, %lf, %lf)\n", str, vec.x, vec.y, vec.z);
}
