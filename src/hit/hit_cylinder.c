/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:53:24 by yoojlee           #+#    #+#             */
/*   Updated: 2021/10/27 17:46:51 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

void	init_coefficient(t_ray *ray, t_cylinder *cylinder, t_vec *coefficient)
{
	t_vec	co;
	t_vec	n;

	n = cylinder->orient;
	co = minus_vec(ray->origin, cylinder->origin);
	coefficient->x = dot_vec(ray->dir, ray->dir) - pow(dot_vec(ray->dir, n), 2.0);
	coefficient->y = 2 * (dot_vec(co, ray->dir) - (dot_vec(co, n) * dot_vec(ray->dir, n)));
	coefficient->z = dot_vec(co, co) - pow(dot_vec(co, n), 2.0) - pow((cylinder->diameter / 2), 2.0);
}

t_vec	get_normal_vec(t_ray *ray, t_cylinder *cylinder)
{
	t_vec	hit_point;
	t_vec	op;
	t_vec	op_cosine;
	t_vec	normal;

	hit_point = add_vec(ray->origin, product_vec(ray->dir, ray->time));
	op = minus_vec(hit_point, cylinder->origin);
	op_cosine = product_vec(cylinder->orient, dot_vec(op, cylinder->orient));
	normal = unit_vec(minus_vec(op, op_cosine));
	if (ray->time == ray->t1)
		normal = unit_vec(product_vec(normal, -1));
	return (normal);
}

int	check_finite_range(t_vec hit_point, t_cylinder *cylinder)
{
	t_vec	op;
	double	dot;

	op = minus_vec(hit_point, cylinder->origin);
	dot = dot_vec(op, cylinder->orient);
	if (dot < 0 || dot > cylinder->height)
		return (0);
	return (1);
}

int	intersect_cylinder(t_cylinder *cylinder, t_ray *ray, t_hit *hit)
{
	int		check;

	hit->point = add_vec(ray->origin, product_vec(ray->dir, ray->time));
	check = check_finite_range(hit->point, cylinder);
	if (check == 1)
		return (1);
	else if (check == 0 && ray->time == ray->t1)
		return (0);
	else if (check == 0 && ray->time == ray->t0)
	{
		ray->time = ray->t1;
		hit->point = add_vec(ray->origin, product_vec(ray->dir, ray->time));
		check = check_finite_range(hit->point, cylinder);
		if (check == 1)
			return (1);
	}
	return (0);
}

int	hit_cylinder(void *obj, t_ray *ray, t_hit *hit)
{
	t_cylinder	*cylinder;
	t_vec		coefficient;

	cylinder = obj;
	init_coefficient(ray, cylinder, &coefficient);
	if (!solve_quadratic(coefficient.x, coefficient.y, coefficient.z, ray))
	{
		return (0);
	}
	if (!intersect_cylinder(cylinder, ray, hit))
	{
		return (0);
	}
	hit->normal = unit_vec(get_normal_vec(ray, cylinder));
	hit->color = cylinder->color;
	hit->origin = ray->origin;
	hit->dir = ray->dir;
	return (1);
}
