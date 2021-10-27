/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:10:52 by dim               #+#    #+#             */
/*   Updated: 2021/10/27 17:49:53 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/minirt.h"
#include "src/parsing/parse.h"

int		main(int argc, char **argv)
{
	t_render	render;

	init_render(&render);
	parsing(argc, argv, &render);
	start_render(&render);
	return (0);
}