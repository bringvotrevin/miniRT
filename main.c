/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:10:52 by dim               #+#    #+#             */
/*   Updated: 2021/10/14 15:51:39 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/minirt.h"

// int		validate(t_render *render)
// {
// 	return (1);
// }

int		main(int argc, void **argv)
{
	t_render	render;

	init_render(&render);
	parse(argc, argv, &render);
	// if (!validate(&render))
	// 	write(1, "validate error\n", 15);
	start_render(&render);
	return (0);
}