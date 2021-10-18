/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 21:53:48 by yoojlee           #+#    #+#             */
/*   Updated: 2021/10/18 21:59:49 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

t_vec	diffuse_light(t_light *light, t_ray *shadow, t_hit *hit)
{
	double		angle;
	t_vec		ratio;

	angle = dot_vec(normalize_vec(shadow->dir), normalize_vec(hit->normal));
	if (angle < 0)
		angle = 0;
	ratio = multi_vec(div_vec(light->color, 255.0f), angle * light->ratio);
	return (ratio);
}

static void	init_shadow_ray(t_light *light, t_ray *shadow, t_hit *hit)
{
	shadow->origin = add_vec(hit->point, multi_vec(hit->normal, 1.0e-6));
	shadow->dir = normalize_vec(sub_vec(light->point, hit->point));
	shadow->time = 0.0f;
}

static void	phong_shading(t_light *light, t_ray *shadow,
											t_hit *hit, t_vec *ratio)
{
	t_vec	diffuse;
	t_vec	specular;

	diffuse = diffuse_light(light, shadow, hit);
	*ratio = add_vec(*ratio, diffuse);
	// specular = specular_light(light, hit);
	// *ratio = add_vec(*ratio, specular);
}

static int	block_light(t_world *world, t_ray *shadow,
										t_hit *dump, t_light *light)
{
	t_vec		tmp;
	double		dist;
	t_object	*obj_group;

	obj_group = world->object;
	tmp = minus_vec(light->origin, shadow->origin);
	dist = sqrt(dot_vec(tmp, tmp));
	while (obj_group)
	{
		if (hit_sphere(obj_group->object, shadow, dump))
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
		
	hit->color = product_vec(hit->color, ratio);
	hit->color.x = ft_min(hit->color.x, 255.0f);
	hit->color.y = ft_min(hit->color.y, 255.0f);
	hit->color.z = ft_min(hit->color.z, 255.0f);
}
