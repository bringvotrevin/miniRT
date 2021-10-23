/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:53:24 by yoojlee           #+#    #+#             */
/*   Updated: 2021/10/22 20:49:18 by yoojlee          ###   ########.fr       */
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
	coefficient->y = 2 * (dot_vec(ray->dir, co) - dot_vec(ray->dir, n) * dot_vec(co, n));
	coefficient->z = dot_vec(co, co) - pow(dot_vec(co, n), 2.0) - pow(cylinder->diameter / 2, 2.0);
}

t_vec	get_normal_vec(t_ray *ray, t_cylinder *cylinder)
{
	t_vec	hit_point;
	t_vec	cp;
	t_vec	foot;
	t_vec	normal;

	hit_point = add_vec(ray->origin, product_vec(ray->dir, ray->time));
	cp = minus_vec(hit_point, cylinder->origin);
	foot = add_vec(cylinder->origin, product_vec(cylinder->orient, dot_vec(cp, cylinder->orient)));
	// if (ray->time == ray->t0)
	normal = unit_vec(minus_vec(cp, foot));
	if (dot_vec(normal, ray->dir) > 0)
	{
		normal = unit_vec(product_vec(normal, -1));
	}
	// else
	// 	normal = unit_vec(product_vec(minus_vec(cp, foot), -1)); //?
	return (normal);
}

// t_vec	get_normal(t_ray *ray, t_cylinder *cylinder, int flag)
// {
// 	t_vec	hit;
// 	t_vec	cp;
// 	t_vec	u;
// 	t_vec	normal;

// 	(void)flag;
// 	hit = add_vec(ray->origin, product_vec(ray->dir, ray->time));
// 	cp = minus_vec(hit, cylinder->origin);
// 	u = product_vec(cylinder->orient, dot_vec(cylinder->orient, cp));
// 	// if (flag == 1)
// 		normal = unit_vec(minus_vec(cp, u));
// 	// else
// 	// 	normal = unit_vec(product_vec(minus_vec(cp, u), -1));
// 	return (normal);
// }

int	hit_cylinder(void *obj, t_ray *ray, t_hit *hit)
{
	t_cylinder	*cylinder;
	t_vec		coefficient;
	t_vec		cp;
	int			flag;

	flag = 1;
	cylinder = obj;
	init_coefficient(ray, cylinder, &coefficient);
	if (!solve_quadratic(coefficient.x, coefficient.y, coefficient.z, ray))
	{
		return (0);
	}
	hit->point = add_vec(ray->origin, product_vec(ray->dir, ray->time));
	cp = minus_vec(hit->point, cylinder->origin);
	if (dot_vec(cp, cylinder->orient) < 0 \
		|| dot_vec(cp, cylinder->orient) > cylinder->height)
	{
		hit->point = add_vec(ray->origin, product_vec(ray->dir, ray->t1));
		ray->time = ray->t1;
		flag = 2;
		cp = minus_vec(hit->point, cylinder->origin);
		if (dot_vec(cp, cylinder->orient) < 0 \
			|| dot_vec(cp, cylinder->orient) > cylinder->height)
		{
			return (0);
		}
	}
	hit->normal = unit_vec(get_normal_vec(ray, cylinder));
	// if (dot_vec(hit->normal, ray->dir) > 0)
	// 	hit->normal = product_vec(hit->normal, -1);
	hit->color = cylinder->color;
	hit->origin = ray->origin;
	hit->dir = ray->dir;
	return (1);
}

// int		solve_cylinder(t_ray *ray, t_cylinder *cylinder,
// 					double radius, double height)
// {
// 	t_ray		tmp;
// 	t_vec		coefficient;
// 	t_vec		hit;
// 	t_vec		cp;

// 	init_coefficient(ray, cylinder, radius, &coefficient);
// 	if (!solve_quadratic(coefficient.x, coefficient.y, coefficient.z, ray))
// 		return (0);
// 	hit = add_vec(ray->origin, product_vec(ray->dir, ray->time));
// 	cp = minus_vec(hit, cylinder->point);
// 	if (dot_vec(cp, cylinder->orient) <= height
// 			&& dot_vec(cp, cylinder->orient) >= 0)
// 		return (1);
// 	tmp = *ray;
// 	tmp.origin = add_vec(hit, product_vec(ray->dir, 1e-5));
// 	init_coefficient(&tmp, cylinder, radius, &coefficient);
// 	if (!solve_quadratic(coefficient.x, coefficient.y, coefficient.z, &tmp))
// 		return (0);
// 	hit = add_vec(tmp.origin, product_vec(tmp.dir, tmp.time));
// 	cp = minus_vec(hit, cylinder->point);
// 	if (dot_vec(cp, cylinder->orient) > height
// 			|| dot_vec(cp, cylinder->orient) < 0)
// 		return (0);
// 	ray->time = tmp.time;
// 	return (2);
// }