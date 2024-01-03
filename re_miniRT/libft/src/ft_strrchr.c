/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:38:41 by minjcho           #+#    #+#             */
/*   Updated: 2022/12/14 14:17:51 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*tmp;

	tmp = (char *)s;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (tmp[i] == (char)c)
			return (tmp + i);
		i--;
	}
	if (tmp[i] == (char)c)
		return (tmp);
	return (0);
}
