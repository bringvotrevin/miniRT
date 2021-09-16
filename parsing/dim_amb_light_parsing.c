/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_amb_light_parsing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 04:41:04 by dim               #+#    #+#             */
/*   Updated: 2021/09/16 20:13:20 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dim_amb_light.h"

void	amb_light_parsing(t_render *render, char **split_line)
{
	double		light_ratio;
	t_vector	rgb;

	if (count_split_line(split_line) != 3)
		error("Information count error on Ambient lightning");
	if (!validate_float(split_line[1]) ||\
	 !validate_vec(split_line[2]))
		error("Information error on Ambien lightning");
	light_ratio = ft_atof(split_line[1]);
	split_vec(&rgb, split_line[2]);
	if (!validate_amb_light(light_ratio, &rgb))
		error("Information range error on Ambient lightning");
	render->world.ambient_light = save_amb_light(light_ratio, &rgb);
	if (render->world.ambient_light == NULL)
		error(NULL);
	// printf("x : %f\ny : %f\nz : %f\n", \
	// render->world.ambient_light->x, \
	// render->world.ambient_light->y, render->world.ambient_light->z);
}

bool		validate_amb_light(double light_ratio, t_vector *rgb)
{
	bool	flag;

	flag = true;
	if (light_ratio < 0.0 || light_ratio > 1.0)
		flag = false;
	if (rgb->x < 0 || rgb->x > 255 || \
	rgb->y < 0 || rgb->y > 255 || \
	rgb->z < 0 || rgb->z > 255)
		flag = false;
	return (flag);
}

t_vector	*save_amb_light(double light_ratio, t_vector *rgb)
{
	t_vector	*aloc_rgb;
	
	aloc_rgb = (t_vector *)malloc(sizeof(t_vector));
	if (aloc_rgb == NULL)
		return (NULL);
	aloc_rgb = rgb;
	return (aloc_rgb);
}