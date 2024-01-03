/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:44:01 by minjcho           #+#    #+#             */
/*   Updated: 2022/12/14 19:57:50 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s11 = (unsigned char *)s1;
	const unsigned char	*s22 = (unsigned char *)s2;
	size_t				i;

	i = -1;
	while (++i < n)
		if (s11[i] != s22[i])
			return (s11[i] - s22[i]);
	return (0);
}
