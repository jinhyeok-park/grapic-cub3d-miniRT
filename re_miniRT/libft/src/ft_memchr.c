/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:42:02 by minjcho           #+#    #+#             */
/*   Updated: 2022/12/24 13:31:00 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{	
	unsigned char	*tmp;
	size_t			i;

	tmp = (unsigned char *)s;
	i = -1;
	while (++i < n)
		if (tmp[i] == (unsigned char)c)
			return (&tmp[i]);
	return (0);
}
