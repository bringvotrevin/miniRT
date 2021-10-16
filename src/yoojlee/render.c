/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:24:32 by dim               #+#    #+#             */
/*   Updated: 2021/10/16 15:24:00 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

int	end_render(t_render *render)
{
	//clear_render(render);
	render = NULL;
	exit(0);
	return (0);
}

void	start_render(t_render *render)
{
	create_mlx(&render->trace);
	start_trace(&render->trace, &render->world);
	if (render->control.save)
	{
		/* if (make_bmp(&render->trace))
			error(NULL, end_render, render); */
		//end_render(render);
	}
	else
	{
		mlx_hook(render->trace.mlx_win, 2, 1L << 0, end_render, render);
		mlx_hook(render->trace.mlx_win, 17, 1L << 17, end_render, render);
		mlx_loop(render->trace.mlx);
	}
}
