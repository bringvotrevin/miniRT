/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:53:24 by yoojlee           #+#    #+#             */
/*   Updated: 2021/10/23 14:34:31 by yoojlee          ###   ########.fr       */
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
	coefficient->y = 2 * (dot_vec(ray->dir, co) - (dot_vec(ray->dir, n) * dot_vec(co, n)));
	coefficient->z = dot_vec(co, co) - pow(dot_vec(co, n), 2.0) - pow(cylinder->diameter / 2, 2.0);
}

t_vec	get_normal_vec(t_ray *ray, t_cylinder *cylinder)
{
	t_vec	hit_point;
	t_vec	op;
	t_vec	op_cosine;
	t_vec	normal;

	hit_point = add_vec(ray->origin, product_vec(ray->dir, ray->time));
	op = minus_vec(hit_point, cylinder->origin);
	op_cosine = add_vec(cylinder->origin, product_vec(cylinder->orient, dot_vec(op, cylinder->orient)));
	// if (ray->time == ray->t0)
	normal = unit_vec(minus_vec(op, op_cosine));
	// if (dot_vec(normal, ray->dir) > 0)
	// {
	// 	normal = unit_vec(product_vec(normal, -1));
	// }
	// else
	// 	normal = unit_vec(product_vec(minus_vec(cp, op_cosine), -1)); //?
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
	// if (dot >= 0 && dot <= cylinder->height)
	// 	return (1);
	// return (0);
}

int	intersect_cylinder(t_cylinder *cylinder, t_ray *ray, t_hit *hit)
{
	t_vec	op;
	int		check;

	hit->point = add_vec(ray->origin, product_vec(ray->dir, ray->time));
	check = check_finite_range(hit->point, cylinder);
	if (check == 1)
		return (1);
	else if (ray->time == ray->t1)
		return (0);
	else
	{
		hit->point = add_vec(ray->origin, product_vec(ray->dir, ray->t1));
		check = check_finite_range(hit->point, cylinder);
		if (check == 1)
			return (2);
	}
	return (0);
}

int	hit_cylinder(void *obj, t_ray *ray, t_hit *hit)
{
	t_cylinder	*cylinder;
	t_vec		coefficient;
	t_vec		cp;
	int			flag;

	cylinder = obj;
	init_coefficient(ray, cylinder, &coefficient);
	if (!solve_quadratic(coefficient.x, coefficient.y, coefficient.z, ray))
	{
		return (0);
	}
	flag = intersect_cylinder(cylinder, ray, hit);
	if (flag == 0)
	{
		return (0);
	}
	if (flag == 2)
	{
		ray->time = ray->t1;
	}
	hit->normal = unit_vec(get_normal_vec(ray, cylinder));
	hit->color = cylinder->color;
	hit->origin = ray->origin;
	hit->dir = ray->dir;	
	if (dot_vec(hit->normal, ray->dir) > 0.0f)
	{
		hit->normal = product_vec(hit->normal, -1);
		hit->color = create_vec(0, 0, 0); //왜 이걸 추가했는데 달라지는 게 없지?
		// 이 if문에 들어오지 않으니까.
	}
	return (1);
}
