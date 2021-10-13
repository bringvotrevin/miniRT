/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_cam.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 03:59:02 by dim               #+#    #+#             */
/*   Updated: 2021/10/13 20:57:17 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIM_CAM_H
# define DIM_CAM_H
# include "dim_header.h"

typedef struct	s_cam
{
	t_vec		point;
	t_vec		orient;
	t_vec		matrix[3];
	t_vec		x_axis;
	t_vec		y_axis;
	t_vec		z_axis;
	double		fov;
	double		pan;	
	double		tilt;
	double		viewport_width;
	double		viewport_height;
	double		viewport_ratio;
}				t_cam;

#endif