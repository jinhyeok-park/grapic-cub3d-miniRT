/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:12:29 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/04/07 14:02:16 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_tohex(long long num, int u_sign)
{
	unsigned long long	temp;
	size_t				i;

	temp = num;
	i = 0;
	while (temp)
	{
		i++;
		temp /= 16;
	}
	temp = (unsigned long long)num;
	return (ft_tohex2(temp, i, u_sign));
}

char	*ft_print_0(char *result)
{
	result = (char *)malloc(2);
	if (!result)
		return (0);
	result[0] = '0';
	result[1] = 0;
	return (result);
}

char	*ft_tohex2(unsigned long long temp, size_t i, int u_sign)
{
	char	*result;

	result = 0;
	if (!i)
		return (ft_print_0(result));
	result = (char *)malloc(i + 1);
	if (!result)
		return (0);
	result[i] = 0;
	while (temp)
	{
		if (u_sign)
			result[--i] = "0123456789ABCDEF"[temp % 16];
		else
			result[--i] = "0123456789abcdef"[temp % 16];
		temp /= 16;
	}
	return (result);
}

int	write_s(va_list ap)
{
	char	*s;
	int		f;
	size_t	i;

	s = 0;
	i = 0;
	f = 0;
	s = va_arg(ap, char *);
	if (!s)
		s = "(null)";
	if (2147483647 == ft_strlen(s))
		return (-1);
	while (s[i])
	{
		f = write(1, &s[i++], 1);
		if (f == -1)
			return (f);
	}
	return ((int)i);
}

int	write_c(va_list ap)
{
	unsigned char	temp;
	int				f;

	f = 0;
	temp = va_arg(ap, int);
	f = write(1, &temp, 1);
	return (f);
}
