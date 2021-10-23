/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:55:35 by yoojlee           #+#    #+#             */
/*   Updated: 2021/10/22 18:56:00 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

int	intersect_plane(t_ray *ray, t_vec point, t_vec n)
{
	double	denom;
	t_vec	op;
	double	t;

	n = unit_vec(n);
	denom = dot_vec(ray->dir, n);
	if (denom > 1.0e-6 || denom < -1.0e-6)
	{
		op = minus_vec(point, ray->origin);
		t = dot_vec(op, n) / denom;
		if (t > 1.0e-6)
		{
			ray->time = t;
			return (1);
		}
	}
	ray->time = 0.0f;
	return (0);
}

int	hit_plane(void *obj, t_ray *ray, t_hit *hit)
{
	t_plane		*plane;

	plane = (t_plane *)obj;
	if (!intersect_plane(ray, plane->origin, plane->orient))
		return (0);
	hit->color = plane->color;
	hit->normal = unit_vec(plane->orient);
	if (dot_vec(hit->normal, ray->dir) > 0)
		hit->normal = product_vec(hit->normal, -1);
	hit->point = add_vec(ray->origin, product_vec(ray->dir, ray->time));
	hit->origin = ray->origin;
	hit->dir = ray->dir;
	return (1);
}