/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 21:45:59 by dim               #+#    #+#             */
/*   Updated: 2021/09/30 19:37:26 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dim_parse.h"

t_vector	create_vec(double x, double y, double z)
{
	t_vector	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_vector	add_vec(t_vector v1, t_vector v2)
{
	t_vector	new;

	new.x = v1.x + v2.x;
	new.y = v1.y + v2.y;
	new.z = v1.z + v2.z;
	return (new);
}

t_vector	minus_vec(t_vector v1, t_vector v2)
{
	t_vector	new;

	new.x = v1.x - v2.x;
	new.y = v1.y - v2.y;
	new.z = v1.z - v2.z;
	return (new);
}

t_vector	product_vec(t_vector v, double scalar)
{
	v.x *= scalar;
	v.y *= scalar;
	v.z *= scalar;
	return (v);
}

double	dot_vec(t_vector v1, t_vector v2)
{
	double	ret;

	ret = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (ret);
}

t_vector	cross_vec(t_vector v1, t_vector v2)
{
	t_vector	new;

	new.x = v1.y * v2.z - v1.z * v2.y;
	new.y = v1.z * v2.x - v1.x * v2.z;
	new.z = v1.x * v2.y - v1.y * v2.x;
	return (new);
}

t_vector	unit_vec(t_vector v)
{
	double	size;

	size = sqrt(dot_vec(v, v));
	v.x = v.x / size;
	v.y = v.y / size;
	v.z = v.z / size;
	return (v);
}

// 내가  추가

t_vector	devide_vec(t_vector v, double scala)
{
	v.x *= 1 / scala;
	v.y *= 1 / scala;
	v.z *= 1 / scala;
	return (v);
}
