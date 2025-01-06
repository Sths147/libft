/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:59:36 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/06 17:28:05 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
Inspects the content and sends back 1 if a \n is found
*/

int	ft_inspect_content(t_list *lst)
{
	int		i;
	t_list	*current;

	i = 0;
	if (!lst)
		return (0);
	current = ft_lstlast(lst);
	while (((char *)current->content)[i])
	{
		if (((char *)current->content)[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/*
Adds the buffer at the end of the list
*/

void	ft_lstadd_back_gnl(t_list **lst, char *str, int len)
{
	t_list	*new;
	t_list	*last;
	int		i;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (ft_free_all(lst));
	new->content = (char *)malloc((len + 1) * sizeof(char));
	if (!(new->content))
	{
		free(new);
		return (ft_free_all(lst));
	}
	i = -1;
	while (++i < len)
		((char *)new->content)[i] = str[i];
	((char *)new->content)[i] = '\0';
	new->next = NULL;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
/*
Goes to the last node of list
*/

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst || !lst->next)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
Calculates a list's size
*/

int	ft_size_lst(t_list *lst)
{
	int	i;

	i = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/*
Frees whole list
*/

void	ft_free_all(t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
}
