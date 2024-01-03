/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:40:21 by minjcho           #+#    #+#             */
/*   Updated: 2022/12/24 13:12:12 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s11 = (unsigned char *)s1;
	const unsigned char	*s22 = (unsigned char *)s2;

	if (n == 0)
		return (0);
	i = 0;
	while (s11[i] == s22[i] && i + 1 < n && s11[i])
		i++;
	return (s11[i] - s22[i]);
}
