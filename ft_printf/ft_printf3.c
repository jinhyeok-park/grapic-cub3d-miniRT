/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:20:04 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/04/07 14:22:44 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_longlong(long long num)
{
	size_t		len;
	char		*result;
	long long	temp;

	result = 0;
	temp = num;
	len = 0;
	while (temp)
	{
		temp /= 10;
		len ++;
	}
	if (!len)
		return (ft_print_0(result));
	result = (char *)malloc(len + 1);
	if (!result)
		return (0);
	result[len] = 0;
	temp = num;
	while (temp)
	{
		result[--len] = "0123456789"[temp % 10];
		temp /= 10;
	}
	return (result);
}

int	write_di(va_list ap)
{
	int		len;
	int		f;
	int		temp;
	char	*num;

	len = 0;
	f = 0;
	temp = va_arg(ap, int);
	num = ft_itoa(temp);
	if (!num)
		return (-1);
	while (num[len])
	{
		f = write(1, &num[len++], 1);
		if (f == -1)
			return (f);
	}
	free (num);
	return (len);
}

int	write_p(va_list ap)
{
	int					len;
	int					f;
	char				*temp;
	unsigned long long	address;

	len = 0;
	f = 0;
	address = (unsigned long long)va_arg(ap, void *);
	temp = ft_tohex(address, 0);
	if (ft_free(temp))
		return (-1);
	write(1, "0x", 2);
	while (temp[len])
	{
		f = write(1, &temp[len++], 1);
		if (f == -1)
			return (f);
	}
	free(temp);
	temp = 0;
	return (len + 2);
}

int	ft_free(void *p)
{
	if (!p)
	{
		free(p);
		p = 0;
		return (1);
	}
	return (0);
}
