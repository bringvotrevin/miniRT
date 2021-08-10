/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:21:18 by yoojlee           #+#    #+#             */
/*   Updated: 2021/08/02 03:28:29 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

typedef struct		s_info
{
	char			**content;
	struct s_info	*next;
}					t_info;

#endif
