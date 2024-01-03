/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:53:16 by minjcho           #+#    #+#             */
/*   Updated: 2023/02/21 16:31:19 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base_cnt(unsigned int nb, char *base)
{
	unsigned int	base_len;
	int				count;

	base_len = 0;
	count = 0;
	while (base[base_len])
		base_len++;
	if (nb >= base_len)
		count += ft_putnbr_base_cnt(nb / base_len, base);
	count += ft_putchar_cnt(base[nb % base_len]);
	return (count);
}

int	ft_print_address_cnt(unsigned long address)
{
	const char	*base = "0123456789abcdef";
	int			count;

	count = 0;
	if (address >= 16)
		count += ft_print_address_cnt(address / 16);
	else
		count += ft_putstr_cnt("0x");
	count += ft_putchar_cnt(base[address % 16]);
	return (count);
}

int	ft_print_int(long long format, char type)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += ft_putchar_cnt(format);
	else if (type == 'd' || type == 'i')
		count += ft_putnbr_cnt(format);
	else if (type == 'u')
		count += ft_putnbr_base_cnt(format, "0123456789");
	else if (type == 'x')
		count += ft_putnbr_base_cnt(format, "0123456789abcdef");
	else if (type == 'X')
		count += ft_putnbr_base_cnt(format, "0123456789ABCDEF");
	return (count);
}

bool	is_int(char c)
{
	return (c == 'c' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X');
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	va_start(ap, format);
	count = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%' && ++i)
		{
			if (is_int(format[i]))
				count += ft_print_int(va_arg(ap, int), format[i]);
			else if (format[i] == 's')
				count += ft_putstr_cnt(va_arg(ap, char *));
			else if (format[i] == 'p')
				count += ft_print_address_cnt(va_arg(ap, unsigned long));
			else if (format[i] == '%')
				count += ft_putchar_cnt('%');
		}
		else
			count += ft_putchar_cnt(format[i]);
	}
	va_end(ap);
	return (count);
}
