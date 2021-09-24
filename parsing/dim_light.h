/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_light.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 03:58:59 by dim               #+#    #+#             */
/*   Updated: 2021/09/17 16:17:20 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIM_LIGHT_H
# define DIM_LIGHT_H
# include "dim_header.h"

typedef struct		s_light
{
	t_vector		origin;
	t_vector		color;
}					t_light;

#endif