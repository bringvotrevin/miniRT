/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:24:59 by dim               #+#    #+#             */
/*   Updated: 2021/10/27 18:00:15 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minirt.h"

void	write_pixel(t_trace *mlx, int x, int y, t_vec *rgb)
{
	char			*dst;
	unsigned int	color;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	if (rgb == NULL)
		color = 0x000000;
	else
		color = ((unsigned int)rgb->x) * pow(2, 16.0)
			+ ((unsigned int)rgb->y) * pow(2, 8.0)
			+ ((unsigned int)rgb->z);
	*(unsigned int *)dst = color;
}