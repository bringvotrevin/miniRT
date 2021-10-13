/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 21:45:59 by dim               #+#    #+#             */
/*   Updated: 2021/10/13 20:45:42 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dim_parse.h"

t_vec	create_vec(double x, double y, double z)
{
	t_vec	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_vec	add_vec(t_vec v1, t_vec v2)
{
	t_vec	new;

	new.x = v1.x + v2.x;
	new.y = v1.y + v2.y;
	new.z = v1.z + v2.z;
	return (new);
}

t_vec	minus_vec(t_vec v1, t_vec v2)
{
	t_vec	new;

	new.x = v1.x - v2.x;
	new.y = v1.y - v2.y;
	new.z = v1.z - v2.z;
	return (new);
}

t_vec	product_vec(t_vec v, double scalar)
{
	v.x *= scalar;
	v.y *= scalar;
	v.z *= scalar;
	return (v);
}

double	dot_vec(t_vec v1, t_vec v2)
{
	double	ret;

	ret = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (ret);
}

t_vec	cross_vec(t_vec v1, t_vec v2)
{
	t_vec	new;

	new.x = v1.y * v2.z - v1.z * v2.y;
	new.y = v1.z * v2.x - v1.x * v2.z;
	new.z = v1.x * v2.y - v1.y * v2.x;
	return (new);
}

t_vec	unit_vec(t_vec v)
{
	double	size;

	size = sqrt(dot_vec(v, v));
	v.x = v.x / size;
	v.y = v.y / size;
	v.z = v.z / size;
	return (v);
}

// 내가  추가

t_vec	devide_vec(t_vec v, double scala)
{
	v.x *= 1 / scala;
	v.y *= 1 / scala;
	v.z *= 1 / scala;
	return (v);
}
