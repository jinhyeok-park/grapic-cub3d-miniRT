/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:44:59 by minjcho           #+#    #+#             */
/*   Updated: 2022/12/14 14:37:13 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const size_t	haystack_len = ft_strlen(haystack);
	const size_t	needle_len = ft_strlen(needle);
	size_t			i;
	size_t			j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	if (haystack_len < needle_len || len < needle_len)
		return (0);
	if (haystack_len > len)
		j = len;
	else
		j = haystack_len;
	i = 0;
	while (i + needle_len <= j)
	{
		if (ft_strncmp(haystack + i, needle, needle_len) == 0)
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
