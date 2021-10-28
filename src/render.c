/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+e +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:24:32 by dim               #+#    #+#             */
/*   Updated: 2021/10/28 16:18:39 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minirt.h"

int	end_render_esc(int keycode, t_render *render)
{
	if (keycode == ESC_KEY)
	{	
		clear_render(&render->world);
		clear_mlx_window(&render->trace);
		exit(0);
	}
	return (0);
}

int	end_render(t_render *render)
{
	clear_render(&render->world);
	clear_mlx_window(&render->trace);
	exit(0);
	return (0);
}

void	start_render(t_render *render)
{
	create_mlx(&render->trace);
	start_trace(&render->trace, &render->world);
	mlx_hook(render->trace.mlx_win, 2, 1L << 0, end_render_esc, render);
	mlx_hook(render->trace.mlx_win, 17, 1L << 17, end_render, render);
	mlx_loop(render->trace.mlx);
}
