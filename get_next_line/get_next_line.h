/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:59:18 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/06 17:20:47 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_gnl_list
{
	char			*content;
	struct s_list	*next;
}					t_gnl_list;

int					ft_size_lst(t_list *lst);
int					ft_inspect_content(t_list *lst);
char				*get_next_line(int fd);
void				ft_free_all(t_list **lst);
void				ft_lstadd_back_gnl(t_list **lst, char *str, int len);
t_list				*ft_lstlast(t_list *lst);

#endif