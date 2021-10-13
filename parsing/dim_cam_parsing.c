/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_cam_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 02:53:08 by dim               #+#    #+#             */
/*   Updated: 2021/10/13 20:55:19 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dim_parse.h"
#include "dim_cam.h"

bool	validate_cam(t_vec unit_vec, double fov)
{
	bool	flag;

	flag = true;
	if (unit_vec.x < -1 || unit_vec.x > 1
		|| unit_vec.y < -1 || unit_vec.y > 1
		|| unit_vec.z < -1 || unit_vec.z > 1)
		flag = false;
	if (fov < 0 || fov > 180)
		flag = false;
	return (flag);
}

t_cam	*save_cam(t_vec viewpoint, t_vec orient, double fov1)
{
	t_cam	*cam;

	cam = (t_cam *)malloc(sizeof(t_cam));
	if (cam == NULL)
		return (NULL);
	cam->point = viewpoint;
	cam->orient = unit_vec(orient);
	cam->x_axis;
	cam->fov = fov1;
	return (cam);
}

void	cam_parsing(t_render *render, char **split_line)
{
	double		fov;
	t_vec	viewpoint;
	t_vec	orient;

	if (count_split_line(split_line) != 4)
		error("Information count error on Camera");
	if (!validate_vec(split_line[1])
		|| !validate_vec(split_line[2])
		|| !validate_float(split_line[3]))
		error("Information error on Camera");
	split_vec(&viewpoint, split_line[1]);
	split_vec(&orient, split_line[2]);
	fov = ft_atof(split_line[3]);
	if (!validate_cam(orient, fov))
		error("Information range error on Camera");
	if (render->world.camera != NULL)
		error("duplicated element");
	render->world.camera = save_cam(viewpoint, orient, fov);
	if (render->world.camera == NULL)
		error(NULL);
	// printf("x : %f\ny : %f\nz : %f\n", \
	// render->world.camera->origin.x, \
	// render->world.camera, render->world.ambient_light->z);
}
