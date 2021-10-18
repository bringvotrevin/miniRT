/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:26:58 by dim               #+#    #+#             */
/*   Updated: 2021/10/18 21:53:16 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

int	get_ray_time(double t0, double t1, t_ray *ray)
{
	if (t0 > t1)
		swap_double(&t0, &t1);
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

// int		solve_quadratic(double a, double b, double c, t_ray *ray)
// {
// 	double	discr;
// 	double	q;
// 	double	t0;
// 	double	t1;

// 	discr = b * b - 4 * a * c;
// 	if (discr < 0)
// 		return (0);
// 	else if (discr == 0)
// 	{
// 		t0 = -0.5 * b / a;
// 		t1 = t0;
// 	}
// 	else
// 	{
// 		loss_of_significance(&q, b, discr);
// 		t0 = q / a;
// 		t1 = c / q;
// 	}
// 	return (get_ray_time(t0, t1, ray));
// 	/* if (t0 > 0.0f) 
// 		ray->time = t0;
// 	else if (t0 <= 0.0f && t1 > 0.0f)
// 		ray->time = t1;
// 	if (ray->time <= 0.0f)
// 	{
// 		ray->time = 0.0f;
// 		return (0);
// 	} */
// }

int		solve_quadratic(double a, double b, double c, t_ray *ray)
{
	double	discr;
	double	q;
	double	time0;
	double	time1;

	discr = b * b - 4 * a * c;
	if (discr < 0)
		return (0);
	loss_of_significance(&q, b, discr);
	time1 = q / a;
	time0 = c / q;
	if (time0 > time1)
		swap_double(&time0, &time1);
	if (time0 > 0.0f)
		ray->time = time0;
	else if (time0 <= 0.0f && time1 > 0.0f)
		ray->time = time1;
	if (ray->time <= 0.0f)
	{
		ray->time = 0.0f;
		return (0);
	}
	return (1);
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
