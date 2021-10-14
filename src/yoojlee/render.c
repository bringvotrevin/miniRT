/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:24:32 by dim               #+#    #+#             */
/*   Updated: 2021/10/14 17:31:51 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/minirt.h"

void	start_render(t_render *render)
{
	create_mlx(&render->trace);
	start_trace(&render->trace, &render->world);
	if (render->control.save)
	{
		if (make_bmp(&render->trace))
			error(NULL, clear_render, render);
		end_render(render);
	}
	else
	{
		mlx_hook(render->trace.mlx_win, 2, 1L << 0, loop_render, render);
		mlx_hook(render->trace.mlx_win, 17, 1L << 17, end_render, render);
		mlx_loop(render->trace.mlx);
	}
}
