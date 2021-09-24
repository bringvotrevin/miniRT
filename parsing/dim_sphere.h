/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_sphere.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 03:58:55 by dim               #+#    #+#             */
/*   Updated: 2021/09/17 16:24:22 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIM_SPHERE_H
# define DIM_SPHERE_H
# include "dim_header.h"

typedef struct	s_sphere
{
	t_vector	center;
	t_vector	rgb;
	double		radius;
}				t_sphere;

#endif