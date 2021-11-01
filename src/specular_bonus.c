/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:29:42 by yoojlee           #+#    #+#             */
/*   Updated: 2021/11/01 20:35:01 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minirt.h"

t_vec	specular_light(t_light *light, t_hit *hit)
{
	double		angle;
	t_vec		l;
	t_vec		n;
	t_vec		reflect_vec;
	t_vec		ratio;

	l = minus_vec(light->origin, hit->point);
	n = hit->normal;
	n = product_scalar(n, 2 * dot_vec(l, n));
	reflect_vec = minus_vec(n, l);
	angle = dot_vec(unit_vec(reflect_vec),
			unit_vec(product_scalar(hit->dir, -1)));
	if (angle < 0)
		angle = 0;
	ratio = product_scalar(divide_vec(light->color, 255.0f),
			light->ratio * pow(angle, 200.0));
	return (ratio);
}
