/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:36:37 by sithomas          #+#    #+#             */
/*   Updated: 2024/11/14 16:14:06 by sithomas         ###   ########.fr       */
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

static char	**ft_free(char **tab, int count)
{
	while (count >= 0)
	{
		free(tab[count]);
		count--;
	}
	free(tab);
	return (NULL);
}

static char	**ft_malloc_tab(int d)
{
	char	**tab;

	tab = malloc(d * sizeof(char *));
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

	result = ft_malloc_tab(ft_words(s, c) + 1);
	i = 0;
	count = -1;
	while (s[i] && result)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i > start)
		{
			result[++count] = ft_strdup_custom(s, start, i);
			if (result[count] == NULL)
				return (ft_free(result, count));
		}
	}
	if (result)
		result[++count] = NULL;
	return (result);
}
