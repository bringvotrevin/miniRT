/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 04:45:23 by dim               #+#    #+#             */
/*   Updated: 2021/10/27 20:14:47 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

bool	validate_plane(t_vec orient, t_vec color)
{
	bool	flag;

	flag = true;
	if (orient.x < -1 || orient.x > 1
		|| orient.y < -1 || orient.y > 1
		|| orient.z < -1 || orient.z > 1)
		flag = false;
	if (color.x < 0 || color.x > 255
		|| color.y < 0 || color.y > 255
		|| color.z < 0 || color.z > 255)
	 	flag = false;
	return (flag);
}

t_plane		*save_plane(t_vec origin1, t_vec orient1, t_vec color1)
{
	t_plane		*plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	if (plane == NULL)
		return (NULL);
	plane->origin = origin1;
	plane->orient = unit_vec(orient1);
	plane->color = color1;
	return (plane);
}

void		plane_parsing(t_render *render, char **split_line)
{
	t_vec	origin;
	t_vec	orient;
	t_vec	color;

	if (count_split_line(split_line) != 4)
		error("Information count error on Plane");
	if (!validate_vec(split_line[1])
		|| !validate_vec(split_line[2])
		|| !validate_vec(split_line[3]))
		error("Information error on Plane");
	split_vec(&origin, split_line[1]);
	split_vec(&orient, split_line[2]);
	split_vec(&color, split_line[3]);
	if (!validate_plane(orient, color))
		error("Information range error on Plane");
	if (add_object(&render->world.object,\
			save_plane(origin, orient, color),\
			hit_plane) == NULL)
		error("Parsing Plane error");
}

