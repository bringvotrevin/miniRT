/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_plane.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 18:57:38 by dim               #+#    #+#             */
/*   Updated: 2021/09/17 19:02:06 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIM_PLANE_H
# define DIM_PLANE_H
# include "dim_header.h"

typedef struct	s_plane
{
	t_vector	center;
	t_vector	orient;
	t_vector	rgb;
	double		offset;
}				t_plane;

#endif