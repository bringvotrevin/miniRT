/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_object.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 04:13:50 by dim               #+#    #+#             */
/*   Updated: 2021/10/14 15:36:36 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIM_OBJECT_H
# define DIM_OBJECT_H
# include "dim_header.h"

typedef struct s_object_toolbox
{
	void				(*move)(void *, t_vec);
	void				(*rotate)(void *,
								t_vec (*rotate_orient)(t_vec,
														double),
								double);
	void				(*hit)(void *,
								t_ray *,
								t_vec *);
	void				(*clear)(void *);
	// void				(*refresh)(void *);
}	t_object_toolbox;

typedef struct s_object
{
	void				*object;
	t_object_toolbox	*toolbox;
	// int					stretch_mode;
	struct s_object		*next;
}	t_object;

#endif