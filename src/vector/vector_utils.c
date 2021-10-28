/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:11:34 by dim               #+#    #+#             */
/*   Updated: 2021/10/28 18:31:12 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec	divide_vec(t_vec v, double scalar)
{
	v.x *= 1 / scalar;
	v.y *= 1 / scalar;
	v.z *= 1 / scalar;
	return (v);
}

t_vec	product_vec(t_vec v, double scalar)
{
	v.x *= scalar;
	v.y *= scalar;
	v.z *= scalar;
	return (v);
}

t_vec	product_vec2(t_vec v1, t_vec v2)
{
	t_vec	new;

	new.x = v1.x * v2.x;
	new.y = v1.y * v2.y;
	new.z = v1.z * v2.z;
	return (new);
}
