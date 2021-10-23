/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:18:36 by dim               #+#    #+#             */
/*   Updated: 2021/10/23 11:21:13 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 팡팡코드

#include "../header/minirt.h"

void			init_render(t_render *render)
{
	init_world(&render->world);
	init_trace(&render->trace);
	init_control(&render->control);
}

void	init_trace(t_trace *trace)
{
	trace->width = 1920;
	trace->height = 1080;
	trace->ratio = trace->width / (double)trace->height;
	trace->mlx = NULL;
	trace->mlx_win = NULL;
	trace->img = NULL;
	trace->addr = NULL;
}

void			init_control(t_control *control)
{
	control->select_object = NULL;
	control->save = 0;
}


// void	init_cam_matrix(t_vec (*matrix)[3], double p, double t)
// //회전 변환 행렬
// //(월드좌표축->카메라좌표축과 같은 방향으로)
// {
// 	(*matrix)[0] = create_vec(
// 			cos(p),
// 			-1 * sin(p) * sin(t),
// 			-1 * sin(p) * cos(t));
// 	(*matrix)[1] = create_vec(
// 			sin(p),
// 			cos(p) * sin(t),
// 			cos(p) * cos(t));
// 	(*matrix)[2] = create_vec(
// 			0,
// 			-1 * cos(t),
// 			sin(t));
// }
