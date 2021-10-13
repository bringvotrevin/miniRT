/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_cylinder.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 18:57:55 by dim               #+#    #+#             */
/*   Updated: 2021/10/13 20:46:48 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIM_CYLINDER_H
# define DIM_CYLINDER_H
# include "dim_header.h"

typedef struct	s_circle
{
	t_vec	center;
	t_vec	orient;
	t_vec	color;
	double		radius;
	double		offset;
}				t_circle;

typedef struct	s_cylinder
{
	t_vec	top;
	t_vec	base;
	t_vec	orient;
	t_vec	rgb;
	double		radius;
	double		height;
	t_circle	*top_cap;
	t_circle	*bottom_cap;
}				t_cylinder;

#endif