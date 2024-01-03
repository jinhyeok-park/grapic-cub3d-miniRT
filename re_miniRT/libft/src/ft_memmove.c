/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:53:25 by minjcho           #+#    #+#             */
/*   Updated: 2022/12/13 20:41:09 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*dst1;
	const unsigned char	*src1 = (unsigned char *)src;
	size_t				i;

	if (!dst && !src)
		return (0);
	dst1 = (unsigned char *)dst;
	i = -1;
	if (dst1 < src1)
		while (++i < n)
			dst1[i] = src1[i];
	else
		while (++i < n)
			dst1[n - i - 1] = src1[n - i - 1];
	return (dst);
}
