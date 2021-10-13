/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 17:44:17 by dim               #+#    #+#             */
/*   Updated: 2021/10/14 03:50:45 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIM_HEARDER_H
# define DIM_HEARDER_H
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include "../vector/dim_vector.h"
# include "../../libft/libft.h"
# include "../libft/get_next_line.h"

typedef struct	s_control
{
	bool		save;
}				t_control;

typedef struct	s_trace
{
	void		*mlx;
}				t_trace;

typedef struct	s_ray
{
	t_vec	origin;
	t_vec	dir;
	double	time;	
	t_vec	hit_point;
	t_vec	hit_normal;
	t_vec	color;
}				t_ray; // from jwkim

void		error(char *msg);

#endif