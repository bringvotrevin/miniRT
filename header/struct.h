/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:30:18 by dim               #+#    #+#             */
/*   Updated: 2021/10/14 17:45:52 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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

//==========t_render==========
typedef struct  s_render
{
	t_world		world;
	t_trace		trace;
	t_control	control;
}	t_render;


//==========t_world==========
typedef struct  s_world
{
	t_object			*object;
	t_light				*light;
	t_cam				*cam;
	t_vec				*ambient_light;
	t_object_toolbox    plane_toolbox;
	t_object_toolbox    sphere_toolbox;
	t_object_toolbox    cylinder_toolbox;
}	t_world;
/*
typedef enum	e_key_mode
{
	CAM_MODE,
	OBJ_MODE,
	LIGHT_MODE
}				t_key_mode;
*/




//==============================================

typedef struct s_light
{
	t_vec		origin;
	t_vec		color;
}	t_light;


typedef struct s_cam
{
	t_vec		origin;
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
}	t_cam;

typedef struct s_object_toolbox
{
	void		(*move)(void *, t_vec);
	void		(*hit)(void *, t_ray *, t_vec *);
	void		(*clear)(void *);
	// void		(*refresh)(void *);
}	t_object_toolbox;

typedef struct s_object
{
	void				*object;
	t_object_toolbox	*toolbox;
	// int					stretch_mode;
	struct s_object		*next;
}	t_object;

/*
typedef struct			s_obj_group
{
	void				*object;
	int					(*hit)(void *, t_ray *, t_hit *);
	void				(*translate)(void *, int);
	void				(*rotate)(void *, int, double);
	void				(*scale)(void *, int);
	t_vec				angle;
	struct s_obj_group	*next;
}						t_obj_group;
*/

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

typedef struct s_ray
{
	t_vec	origin;
	t_vec	dir;
	double	time;	
	t_vec	hit_point;
	t_vec	hit_normal;
	t_vec	color;
}	t_ray;

typedef struct s_ray_woo
{
	t_vec	origin;
	t_vec	dir;
	double	time;
}	t_ray_woo;

typedef struct s_hit
{
	t_vec	normal;
	t_vec	point;
	t_vec	dir;
	t_vec	origin;
	t_vec	color;
}	t_hit;

typedef struct s_plane
{
	t_vec	point;
	t_vec	orient;
	t_vec	color;
}	t_plane;

typedef struct s_cylinder
{
	t_vec 	point;
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
