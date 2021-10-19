/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:19:59 by dim               #+#    #+#             */
/*   Updated: 2021/10/19 19:28:33 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  팡팡코드

#include "../../header/minirt.h"

void	init_world(t_world *world)
{
	world->object = NULL;
	world->light = NULL;
	world->cam = NULL;
	world->ambient_light = NULL;
}
