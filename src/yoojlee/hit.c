/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:26:58 by dim               #+#    #+#             */
/*   Updated: 2021/10/21 18:03:17 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"
#include <stdio.h>

int	get_ray_time(double t0, double t1, t_ray *ray)
{
	if (t0 > t1)
		swap_double(&t0, &t1);
	ray->t0 = t0;
	ray->t1 = t1;
	if (t0 < 0.0f)
	{
		t0 = t1;
		if (t0 < 0.0f)
		{
			ray->time = 0.0f;
			return (0);
		}
	}
	ray->time = t0;
	return (1);
}

void	loss_of_significance(double *q, double b, double discr)
{
	if (b > 0)
		*q = -1 / 2.0 * (b + sqrt(discr));
	else
		*q = -1 / 2.0 * (b - sqrt(discr));
}

int		solve_quadratic(double a, double b, double c, t_ray *ray)
{
	double	discr;
	double	q;
	double	t0;
	double	t1;

	discr = b * b - 4 * a * c;
	if (discr < 0)
		return (0);
	else if (discr == 0)
	{
		t0 = -0.5 * b / a;
		t1 = t0;
	}
	else
	{
		loss_of_significance(&q, b, discr);
		t0 = q / a;
		t1 = c / q;
	}
	return (get_ray_time(t0, t1, ray));
}

int	hit_sphere(void *obj, t_ray *ray, t_hit *hit)
{
	t_sphere	*sphere;
	t_vec		co;
	double		a;
	double		b;
	double		c;

	sphere = (t_sphere *)obj;
	co = minus_vec(ray->origin, sphere->center);
	a = dot_vec(ray->dir, ray->dir);
	b = 2 * dot_vec(co, ray->dir);
	c = dot_vec(co, co) - pow(sphere->diameter / 2, 2.0);
	if (!solve_quadratic(a, b, c, ray))
		return (0);
	hit->color = sphere->color;
	hit->point = add_vec(ray->origin, product_vec(ray->dir, ray->time)); //P = O + t*D
	hit->normal = unit_vec(minus_vec(hit->point, sphere->center));
	if (dot_vec(hit->normal, ray->dir) > 0)
		hit->normal = product_vec(hit->normal, -1);
	hit->origin = ray->origin;
	hit->dir = ray->dir;
	return (1);
}

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
	foot = product_vec(cylinder->orient, dot_vec(cp, cylinder->orient));
	if (ray->time == ray->t0)
		normal = unit_vec(minus_vec(cp, foot));
	else
		normal = unit_vec(product_vec(minus_vec(cp, foot), -1)); //?
	return (normal);
}

int	hit_cylinder(void *obj, t_ray *ray, t_hit *hit)
{
	t_cylinder	*cylinder;
	t_vec		coefficient;
	t_vec		cp;

	cylinder = obj;
	init_coefficient(ray, cylinder, &coefficient);
	if (!solve_quadratic(coefficient.x, coefficient.y, coefficient.z, ray))
		return (0);
	hit->point = add_vec(ray->origin, product_vec(ray->dir, ray->time));
	cp = minus_vec(hit->point, cylinder->origin);
	if (dot_vec(cp, cylinder->orient) < 0 \
		|| dot_vec(cp, cylinder->orient) > cylinder->height)
	{
		hit->point = add_vec(ray->origin, product_vec(ray->dir, ray->t1));
		ray->time = ray->t1;
		cp = minus_vec(hit->point, cylinder->origin);
		if (dot_vec(cp, cylinder->orient) < 0 \
			|| dot_vec(cp, cylinder->orient) > cylinder->height)
		return (0);
	}
	hit->normal = unit_vec(get_normal_vec(ray, cylinder));
	if (dot_vec(hit->normal, ray->dir) > 0)
		hit->normal = product_vec(hit->normal, -1);
	hit->color = cylinder->color;
	
	hit->origin = ray->origin;
	hit->dir = ray->dir;
//	print_vec(cylinder->color, "cylinder color");
	return (1);
}
