/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:29:57 by dim               #+#    #+#             */
/*   Updated: 2021/10/19 20:13:43 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "define.h"
# include "struct.h"
# include "../src/vector/vector.h" //우선 여기에 추가함.
# include <mlx.h>
# include <fcntl.h> //open
# include <unistd.h> //close
# include <stdlib.h>
# include <math.h>


//init.c
void		init_render(t_render *render);
void		init_trace(t_trace *trace);
void		init_control(t_control *control);
void		init_cam_matrix(t_vec (*matrix)[3], double p, double t);

//init_world.c
void		init_world(t_world *world);

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
int			hit_cylinder(void *obj, t_ray *ray, t_hit *hit);

//clear.c
void		clear_sphere(void *obj);
void		clear_plane(void *obj);
void		clear_cylinder(void *obj);

//light.c
void		trace_light(t_world *world, t_hit *hit);

//utils.c
void		swap_double(double *a, double *b);
double		check_max(double a, double b);

#endif
