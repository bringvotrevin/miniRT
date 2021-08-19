/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_render.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 04:19:23 by dim               #+#    #+#             */
/*   Updated: 2021/08/15 17:52:32 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIM_RENDER_H
# define DIM_RENDER_H
# include "dim_world.h"

typedef struct	s_render
{
	t_world		world;
	t_control	control;
	t_trace		trace;
}				t_render;

#endif