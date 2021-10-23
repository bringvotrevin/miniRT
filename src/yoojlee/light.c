/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 21:53:48 by yoojlee           #+#    #+#             */
/*   Updated: 2021/10/23 11:07:12 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

t_vec	diffuse_light(t_light *light, t_ray *shadow, t_hit *hit)
{
	double		angle;
	t_vec		ratio;

// printf("DIFFUSE_LIGHT\n");
	angle = dot_vec(unit_vec(shadow->dir), unit_vec(hit->normal));
	if (angle < 0)
		angle = 0;
	ratio = product_vec(divide_vec(light->color, 255.0f), angle * light->ratio);
	return (ratio);
}

t_vec	specular_light(t_light *light, t_hit *hit)
{
	double		angle;
	t_vec		l;
	t_vec		n;
	t_vec		reflect_vec;
	t_vec		ratio;

// printf("SPECULAR_LIGHT\n");
	l = minus_vec(light->origin, hit->point);
	n = hit->normal;
	n = product_vec(n, 2 * dot_vec(l, n));
	reflect_vec = minus_vec(n, l);
	angle = dot_vec(unit_vec(reflect_vec),
					unit_vec(product_vec(hit->dir, -1)));
	if (angle < 0)
		angle = 0;
	ratio = product_vec(divide_vec(light->color, 255.0f),
							light->ratio * pow(angle, 200.0));
	return (ratio);
}

static void	init_shadow_ray(t_light *light, t_ray *shadow, t_hit *hit)
{
	//printf("INIT SHADOW RAY\n");
	shadow->origin = add_vec(hit->point, product_vec(hit->normal, 1.0e-6));
	shadow->dir = unit_vec(minus_vec(light->origin, hit->point));
	shadow->time = 0.0f;
}

static void	phong_shading(t_light *light, t_ray *shadow,
											t_hit *hit, t_vec *ratio)
{
	t_vec	diffuse;
	t_vec	specular;

// printf("PHONG_SHADING\n");
	diffuse = diffuse_light(light, shadow, hit);
	*ratio = add_vec(*ratio, diffuse);
	specular = specular_light(light, hit);
	*ratio = add_vec(*ratio, specular);
}

static int	block_light(t_world *world, t_ray *shadow,
										t_hit *dump, t_light *light)
{
	t_vec		tmp;
	double		dist;
	t_object	*obj_group;

	// printf("BLOCK_LIGHT\n");
	obj_group = world->object;
	tmp = minus_vec(light->origin, shadow->origin);
	dist = sqrt(dot_vec(tmp, tmp));
	while (obj_group)
	{
		if (obj_group->hit(obj_group->object, shadow, dump))
			if (shadow->time > 1.0e-5 && shadow->time < dist)
				if (shadow->time < dist)
					return (1);
		obj_group = obj_group->next;
	}
	return (0);
}

void		trace_light(t_world *world, t_hit *hit)
{
	t_light		*light;
	t_ray		shadow;
	t_hit		tmp;
	t_vec		ratio;

	light = world->light;
	ratio = *world->ambient_light;
	init_shadow_ray(light, &shadow, hit);
	if (dot_vec(shadow.dir, hit->normal) > 0
			&& !block_light(world, &shadow, &tmp, light))
		phong_shading(light, &shadow, hit, &ratio);
	hit->color = product_vec2(hit->color, ratio);
	hit->color.x = check_max(hit->color.x, 255.0f);
	hit->color.y = check_max(hit->color.y, 255.0f);
	hit->color.z = check_max(hit->color.z, 255.0f);
}
