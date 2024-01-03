/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:56:54 by minjcho           #+#    #+#             */
/*   Updated: 2022/11/30 15:14:57 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	const size_t	size = ft_strlen(s1);
	char			*tmp;
	size_t			i;

	i = -1;
	tmp = (char *)malloc(sizeof(char) * (size + 1));
	if (!tmp)
		return (0);
	while (s1[++i])
		tmp[i] = s1[i];
	tmp[i] = '\0';
	return (tmp);
}
