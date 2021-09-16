/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_cam.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 03:59:02 by dim               #+#    #+#             */
/*   Updated: 2021/09/16 20:08:32 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIM_CAM_H
# define DIM_CAM_H
# include "dim_header.h"

typedef struct	s_camera
{
	t_vector		origin;
	// t_vector		orient;
	t_vector		matrix[3]; // from jwkim code
	t_vector		x_axis;
	t_vector		y_axis;
	t_vector		z_axis;
	double			fov;
	double			pan;	
	double			tilt;
	double			viewport_width;
	double			viewport_height;
	double			viewport_ratio;
}				t_camera;

void		cam_parsing(t_render *render, char **split_line);
bool		validate_cam(t_vector unit_vec, double *fov);
t_camera	*save_cam(t_vector viewpoint, t_vector unit_vec, double fov1);

#endif