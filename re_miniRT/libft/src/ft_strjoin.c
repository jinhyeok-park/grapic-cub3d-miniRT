/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:32:43 by minjcho           #+#    #+#             */
/*   Updated: 2022/12/23 00:40:32 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	const size_t	s1_len = ft_strlen(s1);
	const size_t	s2_len = ft_strlen(s2);
	char			*tmp;
	size_t			i;

	tmp = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!tmp)
		return (0);
	i = -1;
	while (++i <= s1_len)
		tmp[i] = s1[i];
	i = 0;
	while (i < s2_len)
	{
		tmp[s1_len + i] = s2[i];
		i++;
	}
	tmp[s1_len + s2_len] = '\0';
	return (tmp);
}
