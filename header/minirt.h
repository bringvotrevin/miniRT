/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:29:57 by dim               #+#    #+#             */
/*   Updated: 2021/10/16 12:58:50 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "define.h"
# include "struct.h"
# include "../src/vector/dim_vector.h" //우선 여기에 추가함.
# include <fcntl.h> //open
# include <unistd.h> //close
# include <stdlib.h>

//main.c
// void		parse(t_render *render, int argc, char **argv);
// int			validate(t_render *render);

//init.c
void		init_render(t_render *render);
void		init_trace(t_trace *trace);
void		init_control(t_control *control);

//init_world.c
void		init_world(t_world *world);
void		init_plane_toolbox(t_object_toolbox *box);
void		init_sphere_toolbox(t_object_toolbox *box);
void		init_cylinder_toolbox(t_object_toolbox *box);

//render.c
void		start_render(t_render *render);

//mlx.c
void		create_mlx(t_trace *trace);

//trace.c
void		start_trace(t_trace *trace, t_world *world);
int			trace_world(t_world *world, t_ray *ray, t_hit *hit);

//ray.c
t_ray		make_ray(t_trace *trace, t_cam *cam, int x, int y);

//pixel.c
void		write_pixel(t_trace *trace, int x, int y, t_vec *color);

//hit.c
int		hit_plane(void *obj, t_ray *ray, t_hit *hit);

//vector.c
// t_vec		create_vec(double x, double y, double z);
// t_vec		add_vec(t_vec v1, t_vec v2);
// t_vec		minus_vec(t_vec v1, t_vec v2);
// t_vec		product_vec(t_vec v, double scalar);
// double		dot_vec(t_vec v1, t_vec v2);
// t_vec		cross_vec(t_vec v1, t_vec v2);
// t_vec		unit_vec(t_vec v);

#endif
