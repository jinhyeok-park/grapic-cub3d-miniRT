/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:55:08 by minjcho           #+#    #+#             */
/*   Updated: 2023/05/07 17:10:36 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;

	if (!s)
		return (0);
	i = ft_strlen(s);
	if (i < (size_t)start)
		len = 0;
	else
	{
		s += start;
		i = ft_strlen(s);
		if (i < len)
			len = i;
	}
	tmp = (char *)malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (0);
	tmp[len] = 0;
	while (len--)
		tmp[len] = s[len];
	return (tmp);
}
