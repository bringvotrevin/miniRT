/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:26:58 by dim               #+#    #+#             */
/*   Updated: 2021/10/14 16:50:02 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/minirt.h"

int		hit_plane(void *obj, t_ray *ray, t_hit *hit)
{
	t_plane		*plane;

	plane = (t_plane *)obj;
	if (!solve_plane(ray, plane->point, plane->orient))
		return (0);
	hit->color = plane->color;
	hit->normal = unit_vec(plane->orient);
	if (dot_vec(hit->normal, ray->dir) > 0)
		hit->normal = product_vec(hit->normal, -1);
	hit->origin = ray->origin;
	hit->point = add_vec(ray->origin, product_vec(ray->dir, ray->time));
	hit->dir = ray->dir;
	return (1);
}