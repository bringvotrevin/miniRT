/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_plane.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 18:57:38 by dim               #+#    #+#             */
/*   Updated: 2021/10/13 20:56:09 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIM_PLANE_H
# define DIM_PLANE_H
# include "dim_header.h"

typedef struct	s_plane
{
	t_vec	center;
	t_vec	orient;
	t_vec	rgb;
	double	offset;
}				t_plane;

#endif