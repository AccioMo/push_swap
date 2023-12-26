/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:47:41 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/26 05:12:11 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(const char *s, char c)
{
	if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
		return (1);
	else
		return (0);
}

static int	count_words(const char *s, char c)
{
	int	words;

	words = 0;
	while (*s)
	{
		if (is_sep(s, c))
			words++;
		s++;
	}
	return (words);
}

static const char	*assign_word(char **tab, const char *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s == c)
		s++;
	while (*(s + len) && *(s + len) != c)
		len++;
	*tab = ft_substr(s, 0, len);
	if (!*tab)
		return (NULL);
	return (s + len);
}

static void	ft_freeall(void **ptr, void *end)
{
	int	i;

	i = 0;
	while (*(ptr + i) != end)
	{
		free(*(ptr + i));
		i++;
	}
	free(ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		words;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	words = count_words(s, c);
	tab = (char **)malloc((words + 1) * sizeof(char *));
	if (!tab)
		return (free(s), exit(1), NULL);
	tab[words] = NULL;
	while (i < words)
	{
		s = assign_word(tab + i, s, c);
		if (s == NULL)
		{
			ft_freeall((void **)tab, *(tab + i));
			free(s);
			exit(1);
		}
		i++;
	}
	free(s);
	return (tab);
}
