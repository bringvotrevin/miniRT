/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 02:50:44 by yoojlee           #+#    #+#             */
/*   Updated: 2021/01/02 05:32:50 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*mem;

	list = NULL;
	while (lst != NULL)
	{
		if (!(mem = ft_lstnew(f(lst->content))))
		{
			if (list != NULL)
				ft_lstclear(&list, del);
			return (NULL);
		}
		ft_lstadd_back(&list, mem);
		lst = lst->next;
	}
	return (list);
}
