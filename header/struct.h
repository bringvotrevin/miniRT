/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:30:18 by dim               #+#    #+#             */
/*   Updated: 2021/10/21 16:42:35 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

//==========t_ray==========
typedef struct s_ray
{
	t_vec	origin;
	t_vec	dir;
	double	time;	
	double	t0;
	double	t1;
}	t_ray;

//==========t_element==========

typedef struct s_light
{
	t_vec		origin;
	double		ratio;
	t_vec		color;
}	t_light;

typedef struct s_cam
{
	t_vec		origin;
	t_vec		orient;
	t_vec		matrix[3];
	double		focal_len;
	double		fov;
	double		pan;	
	double		tilt;
}	t_cam;

typedef struct s_hit
{
	t_vec	normal;
	t_vec	point;
	t_vec	dir;
	t_vec	origin;
	t_vec	color;
}	t_hit;

//==========t_object==========

typedef struct s_object
{
	void				*object;
	int					(*hit)(void *, t_ray *, t_hit *);
	void				(*clear)(void *);
	struct s_object		*next;
}	t_object;

//==========t_control==========
typedef struct s_control
{
//	t_key_mode	mode;
	t_object	*select_object;
	int			save;
}	t_control;

//==========t_trace==========
typedef struct s_trace
{
	void		*mlx; //init.c
	void		*mlx_win; //init.c
	void		*img; //init.c
	char		*addr; //init.c
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	double		width; //init.c
	double		height; //init.c
	double		ratio; //init.c
}	t_trace;

//==========t_world==========
typedef struct  s_world
{
	t_object			*object;
	t_light				*light;
	t_cam				*cam;
	t_vec				*ambient_light;
}	t_world;

//==========t_render==========
typedef struct  s_render
{
	t_world		world;
	t_trace		trace;
	t_control	control;
}	t_render;

//==============================================

typedef struct s_plane
{
	t_vec	origin;
	t_vec	orient;
	t_vec	color;
}	t_plane;

typedef struct s_cylinder
{
	t_vec 	origin;
	t_vec	orient;
	t_vec	color;
	double	diameter;
	double	height;
}	t_cylinder;

typedef struct s_sphere
{
	t_vec	center;
	t_vec	color;
	double	diameter;
}	t_sphere;

#endif
