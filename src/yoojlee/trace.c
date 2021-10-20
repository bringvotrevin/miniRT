/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:24:04 by dim               #+#    #+#             */
/*   Updated: 2021/10/20 20:19:47 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"
#include <stdio.h>

int		trace_world(t_world *world, t_ray *ray, t_hit *hit)
{
	double		time;
	t_hit		tmp_hit;
	t_ray		tmp_ray;
	t_object	*obj;

	time = -1.0f;
	obj = world->object;
	while (obj != NULL)
	{		
		//if (hit_sphere(obj->object, ray, hit))
		if (obj->hit(obj->object, ray, hit))
		{
			if (time < 0 || (ray->time > 1.0e-6 && ray->time < time))
			{
				tmp_hit = *hit;
				tmp_ray = *ray;
				time = ray->time;
			}
		}
		obj = obj->next;
	}
	if (time == -1.0f)
		return (0);
	*ray = tmp_ray;
	*hit = tmp_hit;
	return (1);
}

void	start_trace(t_trace *trace, t_world *world)
{
	t_ray	ray;
	t_hit	hit;
	int		x;
	int		y;

	y = 0;
	while (y < trace->height)
	{
		x = 0;
		while (x < trace->width)
		{
			hit.color = create_vec(0, 0, 0);
			ray = make_ray(trace, world->cam, x, y); 
			if (trace_world(world, &ray, &hit))
			{				
				trace_light(world, &hit);
				write_pixel(trace, x, y, &hit.color);
			}
			else
				write_pixel(trace, x, y, NULL);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(trace->mlx, trace->mlx_win, trace->img, 0, 0);
}
