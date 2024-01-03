/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:52:37 by minjcho           #+#    #+#             */
/*   Updated: 2022/12/23 23:57:16 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	trans_num(int n)
{
	if (n < 0)
		n *= -1;
	return ((unsigned int)n);
}

static int	get_len(unsigned int nb, bool minus)
{
	int	len;

	if (nb == 0)
		return (1);
	len = 0;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	if (minus == true)
		return (len + 1);
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	nb;
	bool			minus;
	int				len;
	char			*tmp;

	minus = false;
	if (n < 0)
		minus = true;
	nb = trans_num(n);
	len = get_len(nb, minus);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (0);
	if (minus == true)
		tmp[0] = '-';
	tmp[len] = '\0';
	tmp[--len] = (nb % 10) + '0';
	while (nb > 9)
	{
		nb /= 10;
		tmp[--len] = (nb % 10) + '0';
	}
	return (tmp);
}
