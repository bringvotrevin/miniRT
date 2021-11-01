/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:17:21 by yoojlee           #+#    #+#             */
/*   Updated: 2021/11/01 20:04:55 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minirt.h"

void	clear_object(t_object *object)
{
	t_object	*cur1;
	t_object	*cur2;

	cur1 = object;
	while (cur1 != NULL)
	{
		cur2 = cur1->next;
		free(cur1->object);
		free(cur1);
		cur1 = cur2;
	}
}

void	clear_render(t_world *world)
{
	free(world->ambient_light);
	free(world->cam);
	free(world->light);
	clear_object(world->object);
}

void	clear_mlx_window(t_trace *trace)
{
	mlx_destroy_image(trace->mlx, trace->img);
	mlx_destroy_window(trace->mlx, trace->mlx_win);
	system("leaks miniRT");
}
