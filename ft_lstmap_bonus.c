/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:06:02 by sithomas          #+#    #+#             */
/*   Updated: 2024/11/14 14:45:01 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*last;
	void	*cont;

	if (!lst || !f || !del)
		return (NULL);
	result = NULL;
	while (lst)
	{
		cont = f(lst->content);
		last = ft_lstnew(cont);
		if (!last)
		{
			del(cont);
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, last);
		lst = lst->next;
	}
	return (result);
}
