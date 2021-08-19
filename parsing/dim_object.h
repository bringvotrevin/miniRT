/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_object.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 04:13:50 by dim               #+#    #+#             */
/*   Updated: 2021/08/18 19:03:04 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIM_OBJECT_H
# define DIM_OBJECT_H
# include "dim_parse.h"

typedef struct			s_object_toolbox
{
	void				(*move)(void *, t_vector);
	void				(*rotate)(void *,
								t_vector (*rotate_orient)(t_vector,
														double),
								double);
	void				(*stretch)(void *,
								double,
								int);
	void				(*hit)(void *,
								t_ray *,
								t_vector *);
	void				(*clear)(void *);
	void				(*refresh)(void *);
	int					stretch_mode;
}						t_object_toolbox;

typedef struct			s_object
{
	void				*object;
	t_object_toolbox	*toolbox;
	int					stretch_mode;
	struct s_object		*next;
}						t_object;

#endif