/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:29:57 by dim               #+#    #+#             */
/*   Updated: 2021/10/16 15:34:42 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "define.h"
# include "struct.h"
# include "../src/vector/dim_vector.h" //우선 여기에 추가함.
# include <mlx.h>
# include <fcntl.h> //open
# include <unistd.h> //close
# include <stdlib.h>
# include <math.h>

//dim header
# include "../src/parsing/dim_parse.h"
# include "../src/parsing/dim_parse_util.h"

//init.c
void		init_render(t_render *render);
void		init_trace(t_trace *trace);
void		init_control(t_control *control);
void		init_cam_matrix(t_vec (*matrix)[3], double p, double t);

//init_world.c
void		init_world(t_world *world);
void		init_plane_toolbox(t_object_toolbox *box);
void		init_sphere_toolbox(t_object_toolbox *box);
void		init_cylinder_toolbox(t_object_toolbox *box);

//render.c
int			end_render(t_render *render);
void		start_render(t_render *render);

//mlx.c
void		create_mlx(t_trace *trace);

//trace.c
void		start_trace(t_trace *trace, t_world *world);
void		trace_light(t_world *world, t_hit *hit);
int			trace_world(t_world *world, t_ray *ray, t_hit *hit);

//ray.c
t_ray		make_ray(t_trace *trace, t_cam *cam, int x, int y);
double		deg_to_rad(double angle);
void		apply_matrix(t_vec *matrix, t_vec *point);

//pixel.c
void		write_pixel(t_trace *trace, int x, int y, t_vec *color);

//hit.c
int			get_ray_time(double t0, double t1, t_ray *ray);
void		loss_of_significance(double *q, double b, double discr);
int			solve_quadratic(double a, double b, double c, t_ray *ray);
int			hit_sphere(void *obj, t_ray *ray, t_hit *hit);
int			hit_plane(void *obj, t_ray *ray, t_hit *hit);

//utils.c
void		swap_double(double *a, double *b);

//vector.c
// t_vec		create_vec(double x, double y, double z);
// t_vec		add_vec(t_vec v1, t_vec v2);
// t_vec		minus_vec(t_vec v1, t_vec v2);
// t_vec		product_vec(t_vec v, double scalar);
// double		dot_vec(t_vec v1, t_vec v2);
// t_vec		cross_vec(t_vec v1, t_vec v2);
// t_vec		unit_vec(t_vec v);

#endif
