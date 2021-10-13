/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:24:25 by dim               #+#    #+#             */
/*   Updated: 2021/10/13 20:25:21 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/minirt.h"

t_ray	make_ray(t_trace *trace, t_cam *cam, int x, int y)
{
	t_ray		ray;
	double		scale;

	ray.origin = cam->origin;
	scale = FOCAL_LEN * tan(deg_to_rad(cam->fov / 2));
	ray.dir.x = (2.0 * ((x + 0.5) / (double)trace->width) - 1.0) * trace->ratio * scale;
	ray.dir.y = (2.0 * ((y + 0.5) / (double)trace->height) - 1.0) * scale;
	ray.dir.z = FOCAL_LEN;
	ray.dir = unit_vec(ray.dir);
	apply_matrix(cam->matrix, &ray.dir);
	ray.time = 0.0f;
	return (ray);
}

double		deg_to_rad(double angle)
{
	return (angle * PI / 180);
}

void		apply_matrix(t_vec *matrix, t_vec *point)
{
	t_vec	new;

	new.x = dot_vec(matrix[0], *point);
	new.y = dot_vec(matrix[1], *point);
	new.z = dot_vec(matrix[2], *point);
	*point = new;
}
