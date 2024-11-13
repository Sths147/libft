/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:36:37 by sithomas          #+#    #+#             */
/*   Updated: 2024/11/05 13:04:04 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			words++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (words);
}

static char	*ft_strdup_custom(char const *s1, int start, int end)
{
	int		i;
	char	*result;

	result = (char *)malloc((end - start + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (start + i < end)
	{
		result[i] = s1[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static void	ft_free(char **tab, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char	**ft_malloc_tab(char const *s, char c)
{
	char	**tab;

	tab = malloc((ft_words(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		start;
	int		count;
	char	**result;

	result = ft_malloc_tab(s, c);
	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i > start)
		{
			result[count] = ft_strdup_custom(s, start, i);
			if (result[count] == NULL)
				ft_free(result, count);
			count++;
		}
	}
	result[count] = NULL;
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	int	i;
	char	**result;
	char const	*s;
	char	c;

	s = "   Bonjour les   amis   ";
	c = ' ';
	result = ft_split(s, c);
	i = 0;
	while (result[i] != NULL)
		printf("%s\n", result[i++]);
	return (0);
}*/
