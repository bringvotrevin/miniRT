/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:10:52 by dim               #+#    #+#             */
/*   Updated: 2021/10/19 20:09:02 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/minirt.h"
#include "src/parsing/parse.h"

int		main(int argc, char **argv)
{
	t_render	render;

	init_render(&render);
	parsing(argc, argv, &render);
	// if (!validate(&render))
	// 	write(1, "validate error\n", 15);
	start_render(&render);
	return (0);
}