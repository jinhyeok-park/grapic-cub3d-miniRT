/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:23:51 by minjcho           #+#    #+#             */
/*   Updated: 2023/02/21 16:30:42 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_cnt(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_cnt(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (ft_putstr_cnt("(null)"));
	while (str[i])
	{
		count += ft_putchar_cnt(str[i]);
		i++;
	}
	return (count);
}

int	ft_putnbr_cnt(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
		return (count += ft_putstr_cnt("-2147483648"));
	if (nb < 0)
	{
		count += ft_putchar_cnt('-');
		nb = -nb;
	}
	if (nb > 9)
		count += ft_putnbr_cnt(nb / 10);
	count += ft_putchar_cnt(nb % 10 + '0');
	return (count);
}
