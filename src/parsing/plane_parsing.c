/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 04:45:23 by dim               #+#    #+#             */
/*   Updated: 2021/10/14 14:26:16 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dim_parse.h"
#include "dim_plane.h"

bool	validate_plane(t_vec orient, t_vec rgb)
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

t_plane		*save_plane(t_vec origin, t_vec orient, t_vec rgb1)
{
	t_plane		*plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	if (plane == NULL)
		return (NULL);
	plane->center = origin;
	plane->orient = orient; //수정필요
	plane->rgb = rgb1; //수정필요
	return (plane);
}

void		plane_parsing(t_render *render, char **split_line)
{
	t_vec	origin;
	t_vec	orient;
	t_vec	rgb;

	if (count_split_line(split_line) != 4)
		error("Information count error on Plane");
	if (!validate_vec(split_line[1])
		|| !validate_vec(split_line[2])
		|| !validate_vec(split_line[3]))
		error("Information error on Plane");
	split_vec(&origin, split_line[1]);
	split_vec(&orient, split_line[2]);
	split_vec(&rgb, split_line[3]);
	if (!validate_plane(orient, rgb))
		error("Information range error on Plane");
	render->world.object->object = save_plane(origin, orient, rgb);
	if (render->world.object->object == NULL)
		error(NULL);
}

