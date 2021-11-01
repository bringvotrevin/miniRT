/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 04:45:02 by dim               #+#    #+#             */
/*   Updated: 2021/11/01 17:15:29 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

bool	validate_light(double bright, t_vec rgb)
{
	bool	flag;

	flag = true;
	if (bright < 0 || bright > 1)
		flag = false;
	if (rgb.x < 0 || rgb.x > 255
		|| rgb.y < 0 || rgb.y > 255
		|| rgb.z < 0 || rgb.z > 255)
		flag = false;
	return (flag);
}

t_light	*save_light(t_vec origin1, double bright, t_vec rgb)
{
	t_light		*light;

	light = (t_light *)malloc(sizeof(t_light));
	if (light == NULL)
		return (NULL);
	light->origin = origin1;
	light->ratio = bright;
	light->color = rgb;
	return (light);
}

void	light_parsing(t_render *render, char **split_line)
{
	double		bright;
	t_vec		origin;
	t_vec		rgb;

	if (count_split_line(split_line) != 4)
		error("Information count error on Light");
	if (!validate_vec(split_line[1])
		|| !validate_float(split_line[2])
		|| !validate_vec(split_line[3]))
		error("Information error on Light");
	split_vec(&origin, split_line[1]);
	bright = ft_atof(split_line[2]);
	split_vec(&rgb, split_line[3]);
	if (!validate_light(bright, rgb))
		error("Information range error on Light");
	if (render->world.light != NULL)
		error("Duplicated element on Light");
	render->world.light = save_light(origin, bright, rgb);
	if (render->world.light == NULL)
		error(NULL);
}
