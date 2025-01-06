/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:59:33 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/06 17:27:20 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_leftover(t_list **lst, char leftover[BUFFER_SIZE + 1]);
static char	*ft_fill_this_str(t_list **stash);
static void	ft_fill_my_stash(t_list **stash, int fd, char *leftover);
static void	ft_assign(char *str, t_list **lst);

/*
Get_next_line behaviour :
	1. Goes through my fd while and fills my chained list with nodes
	 of buffer size while there is no /n or file ends
2. Once my chained list is filled, it :
	* Calculates the length of my list
	* Allocates a str (Result) that has the length of my list * BUFFER SIZE
	* pastes the results in the str
3. Then, cleaning :
	* stacks in my static variable what is after my '\n' in my last node
	* cleans my whole list
*/
char	*get_next_line(int fd)
{
	t_list		*stash;
	char		*result;
	static char	leftover[BUFFER_SIZE + 1];

	result = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (leftover[0] == '\0')
		stash = NULL;
	else
	{
		stash = malloc(sizeof(t_list));
		if (!stash)
			return (NULL);
		ft_assign(leftover, &stash);
	}
	ft_fill_my_stash(&stash, fd, leftover);
	if (!stash)
		return (NULL);
	result = ft_fill_this_str(&stash);
	ft_leftover(&stash, leftover);
	ft_free_all(&stash);
	return (result);
}

/*
If there is a leftover, it initialises chained list with leftover
*/

static void	ft_assign(char *str, t_list **lst)
{
	int	i;

	i = 0;
	if (!*lst)
		return ;
	(*lst)->content = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!(*lst)->content)
		return (ft_free_all(lst));
	while (i < BUFFER_SIZE && str[i] != '\0')
	{
		((char *)(*lst)->content)[i] = str[i];
		i++;
	}
	((char *)(*lst)->content)[i] = '\0';
	(*lst)->next = NULL;
}

/*
Fills my list until there is a \n in BUFFER
*/

static void	ft_fill_my_stash(t_list **stash, int fd, char *leftover)
{
	char	*temp;
	int		bytes_read;

	bytes_read = 1;
	while ((ft_inspect_content(*stash) == 0) && (bytes_read != 0))
	{
		temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!temp)
			return (ft_free_all(stash));
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0 || (bytes_read == 0 && !(*stash)))
		{
			free(temp);
			ft_free_all(stash);
			leftover[0] = '\0';
			return ;
		}
		temp[bytes_read] = '\0';
		ft_lstadd_back_gnl(stash, temp, bytes_read);
		free(temp);
		if (!*stash)
			return (ft_free_all(stash));
	}
}

/*
Fills the result with the whole list until there is a \n
*/

static char	*ft_fill_this_str(t_list **stash)
{
	int		i;
	int		j;
	char	*line;
	t_list	*l;

	l = *stash;
	line = (char *)malloc(((ft_size_lst(l) * BUFFER_SIZE) + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (l)
	{
		j = 0;
		while (((char *)l->content)[j])
		{
			line[i++] = ((char *)l->content)[j++];
			if (((char *)l->content)[j - 1] == '\n')
				break ;
		}
		if (!(l->next))
			break ;
		l = l->next;
	}
	line[i] = '\0';
	return (line);
}

/*
Fills the static with what is left after the \n
*/

static char	*ft_leftover(t_list **lst, char leftover[BUFFER_SIZE + 1])
{
	t_list	*last;
	int		i;
	int		j;

	i = 0;
	while (i < BUFFER_SIZE)
		leftover[i++] = '\0';
	i = 0;
	j = 0;
	if (!(*lst))
		return (NULL);
	last = ft_lstlast(*lst);
	if (!last->content || !ft_inspect_content(last))
		return (NULL);
	while (((char *)last->content)[i])
		if (((char *)last->content)[i++] == '\n')
			break ;
	if (((char *)last->content)[i] != '\0')
		while (((char *)last->content)[i] != '\0')
			leftover[j++] = ((char *)last->content)[i++];
	return (leftover);
}
