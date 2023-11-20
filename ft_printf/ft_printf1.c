/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:42:48 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/06/14 17:39:04 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		len;
	int		temp;
	size_t	i;
	va_list	ap;

	if (write(1, NULL, 0) == -1)
		return (-1);
	va_start(ap, s);
	len = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == '%')
			temp = groupby_write(ap, s + i++ + 1);
		else
			temp = write(1, &s[i], 1);
		if (temp != -1)
			len += temp;
		else
			return (-1);
	}
	va_end(ap);
	return (len);
}

int	groupby_write(va_list ap, const char *s)
{
	int	len;

	len = 0;
	if (*s == 'c')
		len += write_c(ap);
	else if (*s == 's')
		len += write_s(ap);
	else if (*s == 'p')
		len += write_p(ap);
	else if (*s == 'd' || *s == 'i')
		len += write_di(ap);
	else if (*s == '%')
		len += write(1, "%", 1);
	else if (*s == 'u')
		len += write_xxu(ap, -1);
	else if (*s == 'x')
		len += write_xxu(ap, 0);
	else
		len += write_xxu(ap, 1);
	return (len);
}

int	write_xxu(va_list ap, int sign)
{
	int				len;
	int				f;
	char			*temp;
	unsigned int	num;

	len = 0;
	f = 0;
	num = va_arg(ap, unsigned int);
	if (sign == -1)
		temp = ft_itoa_longlong(num);
	else
		temp = ft_tohex(num, sign);
	if (!temp)
		return (-1);
	while (temp[len])
	{
		f = write(1, &temp[len++], 1);
		if (f == -1)
			return (f);
	}
	free(temp);
	temp = 0;
	return (len);
}
