/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 04:45:12 by dim               #+#    #+#             */
/*   Updated: 2021/10/14 14:24:56 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dim_parse.h"
#include "dim_cylinder.h"

bool	validate_cylinder(t_vec orient, t_vec rgb)
{
	bool	flag;

	flag = true;
	if (orient.x < -1 || orient.x > 1
		|| orient.y < -1 || orient.y > 1
		|| orient.z < -1 || orient.z > 1)
		flag = false;
	if (rgb.x < 0 || rgb.x > 255
		|| rgb.y < 0 || rgb.y > 255
		|| rgb.z < 0 || rgb.z > 255)
	 	flag = false;
	return (flag);
}

t_cylinder	*save_cylinder(t_vec origin, t_vec orient1,
							double diameter, double height1, t_vec rgb1)
{
	t_cylinder		*cylinder;

	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (cylinder == NULL)
		return (NULL);
	// cylinder->top = ;
	// cylinder->base = ;
	(void)origin;
	cylinder->orient = orient1;
	cylinder->rgb = rgb1;
	cylinder->radius = (diameter / 2);
	cylinder->height = height1;
	// cylinder->top_cap = ;
	// cylinder->bottom_cap = ;
	return (cylinder);
}

void		cylinder_parsing(t_render *render, char **split_line)
{
	t_vec	origin;
	t_vec	orient;
	double		diameter;
	double		height;
	t_vec	rgb;

	if (count_split_line(split_line) != 6)
		error("Information count error on Cylinder");
	if (!validate_vec(split_line[1])
		|| !validate_vec(split_line[2])
		|| !validate_float(split_line[3])
		|| !validate_float(split_line[4])
		|| !validate_vec(split_line[5]))
		error("Information error on Cylinder");
	split_vec(&origin, split_line[1]);
	split_vec(&orient, split_line[2]);
	diameter = ft_atof(split_line[3]);
	height = ft_atof(split_line[4]);
	split_vec(&rgb, split_line[5]);
	if (!validate_cylinder(orient, rgb))
		error("Information range error on Cylinder");
	render->world.object->object = 
		save_cylinder(origin, orient, diameter, height, rgb);
	if (render->world.object->object == NULL)
		error(NULL);
}
