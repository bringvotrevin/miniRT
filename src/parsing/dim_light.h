/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_light.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 03:58:59 by dim               #+#    #+#             */
/*   Updated: 2021/10/14 15:25:41 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIM_LIGHT_H
# define DIM_LIGHT_H
# include "../vector/dim_vector.h"

typedef struct		s_light
{
	t_vec		origin;
	t_vec		color;
}					t_light;

#endif