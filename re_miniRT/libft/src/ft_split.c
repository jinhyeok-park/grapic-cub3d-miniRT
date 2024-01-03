/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:28:42 by minjcho           #+#    #+#             */
/*   Updated: 2024/01/03 12:28:55 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*tmp;

	i = 0;
	if (n == 0)
		return (0);
	tmp = (char *)malloc(sizeof(char) * (n + 1));
	if (tmp == 0)
		return (0);
	while (i < n)
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

static char	**free_all(char **list)
{
	size_t	j;

	j = 0;
	while (list[j])
	{
		free(list[j]);
		j++;
	}
	free(list);
	return (0);
}

static size_t	count_word(char const *s, char c)
{
	size_t	listsize;
	size_t	i;

	i = 0;
	listsize = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c)
			|| (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c))
			listsize++;
		i++;
	}
	return (listsize);
}

char	**ft_split(char const *s, char c)
{
	char	**tmp;
	size_t	i;
	size_t	k;
	size_t	save;

	i = 0;
	k = 0;
	tmp = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!tmp)
		return (0);
	while (i < count_word(s, c) && s[k] != '\0')
	{
		while (s[k] == c)
			k++;
		save = k;
		while (s[k] != c && s[k] != '\0')
			k++;
		tmp[i] = ft_strndup(&s[save], k - save);
		if (tmp[i++] == 0)
			return (free_all(tmp));
	}
	tmp[i] = 0;
	return (tmp);
}
