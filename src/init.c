/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:18:36 by dim               #+#    #+#             */
/*   Updated: 2021/10/28 16:59:09 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minirt.h"

void	init_world(t_world *world)
{
	world->object = NULL;
	world->light = NULL;
	world->cam = NULL;
	world->ambient_light = NULL;
}

void	init_trace(t_trace *trace)
{
	trace->width = 1920;
	trace->height = 1080;
	trace->ratio = trace->width / (double)trace->height;
	trace->mlx = NULL;
	trace->mlx_win = NULL;
	trace->img = NULL;
	trace->addr = NULL;
}

void	init_render(t_render *render)
{
	init_world(&render->world);
	init_trace(&render->trace);
}

void	init_shadow_ray(t_light *light, t_ray *shadow, t_hit *hit)
{
	shadow->origin = add_vec(hit->point, product_vec(hit->normal, 1.0e-6));
	shadow->dir = unit_vec(minus_vec(light->origin, hit->point));
	shadow->time = 0.0f;
}
