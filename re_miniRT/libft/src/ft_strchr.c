/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:37:38 by minjcho           #+#    #+#             */
/*   Updated: 2023/02/09 16:05:01 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*tmp;

	tmp = (char *)s;
	i = -1;
	while (tmp[++i] != (unsigned char)c)
		if (tmp[i] == '\0')
			return (0);
	return (&tmp[i]);
}
