/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_cylinder.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 18:57:55 by dim               #+#    #+#             */
/*   Updated: 2021/09/17 19:04:30 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIM_CYLINDER_H
# define DIM_CYLINDER_H
# include "dim_header.h"

typedef struct	s_circle
{
	t_vector	center;
	t_vector	orient;
	t_vector	color;
	double		radius;
	double		offset;
}				t_circle;

typedef struct	s_cylinder
{
	t_vector	top;
	t_vector	base;
	t_vector	orient;
	t_vector	rgb;
	double		radius;
	double		height;
	t_circle	*top_cap;
	t_circle	*bottom_cap;
}				t_cylinder;

#endif