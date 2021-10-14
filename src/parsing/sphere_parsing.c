/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 04:45:27 by dim               #+#    #+#             */
/*   Updated: 2021/10/14 16:46:51 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dim_parse.h"

bool	validate_sphere(t_vec color)
{
	bool	flag;

	flag = true;
	if (color.x < 0 || color.x > 255
		|| color.y < 0 || color.y > 255
		|| color.z < 0 || color.z > 255)
	 	flag = false;
	return (flag);
}

t_sphere	*save_sphere(t_vec point, double diameter, t_vec color1)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (sphere == NULL)
		return (NULL);
	sphere->center = point;
	sphere->diameter = (diameter / 2);
	sphere->color = color1;
	return (sphere);
}

void		sphere_parsing(t_render *render, char **split_line)
{
	t_vec	point;
	double		diameter;
	t_vec	color;

	if (count_split_line(split_line) != 4)
		error("Information count error on Sphere");
	if (!validate_vec(split_line[1])
		|| !validate_float(split_line[2])
		|| !validate_vec(split_line[3]))
		error("Information error on Sphere");
	split_vec(&point, split_line[1]);
	diameter = ft_atof(split_line[3]);
	split_vec(&color, split_line[2]);
	if (!validate_sphere(color))
		error("Information range error on Sphere");
	render->world.object->object = save_sphere(point, diameter, color);
	if (render->world.object->object == NULL)
		error(NULL);
}

