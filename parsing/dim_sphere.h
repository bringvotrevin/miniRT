/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_sphere.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 03:58:55 by dim               #+#    #+#             */
/*   Updated: 2021/10/13 20:58:29 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIM_SPHERE_H
# define DIM_SPHERE_H
# include "dim_header.h"

typedef struct	s_sphere
{
	t_vec	center;
	t_vec	rgb;
	double	radius;
}	t_sphere;

#endif