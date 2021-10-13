/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:24:59 by dim               #+#    #+#             */
/*   Updated: 2021/10/13 20:25:08 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/minirt.h"

void	write_pixel(t_trace *trace, int x, int y, t_vec *color)
{
	unsigned int	*pixel;
	unsigned int	u_color;

	pixel = (unsigned int *)(trace->addr + x *
							(trace->bits_per_pixel / 8) +
							y * trace->line_length);
	*pixel = 0;
	u_color = color->x * 255.99;
	u_color = u_color > 255 ? 255 : u_color;
	*pixel = 256 * *pixel + u_color;
	u_color = color->y * 255.99;
	u_color = u_color > 255 ? 255 : u_color;
	*pixel = 256 * *pixel + u_color;
	u_color = color->z * 255.99;
	u_color = u_color > 255 ? 255 : u_color;
	*pixel = 256 * *pixel + u_color;
}
