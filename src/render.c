/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:24:32 by dim               #+#    #+#             */
/*   Updated: 2021/10/27 21:13:51 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minirt.h"

// void	clear_object(t_object *object)
// {
// 	t_object *cur1;
// 	t_object *cur2;

// 	cur1 = object;
// 	while (cur1 != NULL)
// 	{
// 		cur2 = cur1->next;
// 		free(cur1->object);
// 		free(cur1);
// 		cur1 = cur2;
// 	}
// }

// void	clear_render(t_render *render)
// {
// 	(void)render;
// 	// free(render->world.ambient_light);
// 	// free(render->world.cam);
// 	// free(render->world.light);
// 	// clear_object(render->world.object);
// }

int	end_render(t_render *render)
{
	// clear_render(render);
	(void)render;
	exit(0);
	return (0);
}

void	start_render(t_render *render)
{
	create_mlx(&render->trace);
	start_trace(&render->trace, &render->world);
	// if (render->control.save)
	// {
	// 	/* if (make_bmp(&render->trace))
	// 		error(NULL, end_render, render); */
	// 	//end_render(render);
	// }
	// else
	// {
	mlx_hook(render->trace.mlx_win, 2, 1L << 0, end_render, render);
	mlx_hook(render->trace.mlx_win, 17, 1L << 17, end_render, render);
	mlx_loop(render->trace.mlx);
	// }
}
