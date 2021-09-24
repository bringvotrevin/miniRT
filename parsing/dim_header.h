/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 17:44:17 by dim               #+#    #+#             */
/*   Updated: 2021/09/17 03:53:12 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIM_HEARDER_H
# define DIM_HEARDER_H
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

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
	t_vector	origin;
	t_vector	dir;
	double		time;
}				t_ray; // from jwkim

void		error(char *msg);

#endif