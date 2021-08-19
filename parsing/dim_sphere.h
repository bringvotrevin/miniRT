/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_sphere.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 03:58:55 by dim               #+#    #+#             */
/*   Updated: 2021/08/17 03:30:24 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIM_SPHERE_H
# define DIM_SPHERE_H
# include "dim_object.h"

typedef struct	s_sphere
{
	t_vector	center;
	t_vector	rgb;
	double		radius;
}				t_sphere;

#endif