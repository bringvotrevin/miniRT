/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 02:53:08 by dim               #+#    #+#             */
/*   Updated: 2021/10/17 17:39:40 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dim_parse_util.h"

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

void	init_cam_matrix(t_vec (*matrix)[3], double p, double t)
//회전 변환 행렬
//(월드좌표축->카메라좌표축과 같은 방향으로)
{
	(*matrix)[0] = create_vec(
			cos(p),
			-1 * sin(p) * sin(t),
			-1 * sin(p) * cos(t));
	(*matrix)[1] = create_vec(
			sin(p),
			cos(p) * sin(t),
			cos(p) * cos(t));
	(*matrix)[2] = create_vec(
			0,
			-1 * cos(t),
			sin(t));
}

void	init_cam_angle(double *p, double *t, t_vec dir)
{
	double	a;
	double	b;
	double	c;

	a = dir.x;
	b = dir.y;
	c = dir.z;
	*t = asin(c);
	if (c <= 1 + 1.0e-6 && c >= 1 - 1.0e-6)
		*p = 0;
	else
		*p = acos(b / cos(*t));
	if (a > 0)
		*p *= -1;
}

t_cam	*save_cam(t_vec viewpoint, t_vec orient, double fov1)
{
	t_cam	*cam;

	cam = (t_cam *)malloc(sizeof(t_cam));
	if (cam == NULL)
		return (NULL);
	cam->origin = viewpoint;
	cam->orient = unit_vec(orient);
	cam->fov = fov1;
	cam->focal_len = 5;
	init_cam_angle(&cam->pan, &cam->tilt, cam->orient);
	init_cam_matrix(&cam->matrix, cam->pan, cam->tilt);
	return (cam);
}

void	cam_parsing(t_render *render, char **split_line)
{
	double	fov;
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
	if (render->world.cam != NULL)
		error("duplicated element");
	render->world.cam = save_cam(viewpoint, orient, fov);
	if (render->world.cam == NULL)
		error(NULL);
}
