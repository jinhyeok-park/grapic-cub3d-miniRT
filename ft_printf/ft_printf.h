/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:17:28 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/04/07 14:41:23 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

int		groupby_write(va_list ap, const char *s);
int		ft_printf(const char *s, ...);
int		write_c(va_list ap);
int		write_s(va_list ap);
int		write_p(va_list ap);
char	*ft_tohex2(unsigned long long temp, size_t i, int u_sign);
char	*ft_tohex(long long num, int u_sign);
int		write_di(va_list ap);
char	*ft_itoa_longlong(long long num);
int		write_xxu(va_list ap, int sign);
char	*ft_print_0(char *result);
int		ft_free(void *p);
//    - 0.# +
// • %c Prints a single character.
// • %s Prints a string (as defined by the common C convention).
// • %p The void * pointer argument has to be printed in hexadecimal format.
// • %d Prints a decimal (base 10) number.
// • %i Prints an integer in base 10.
// • %u Prints an unsigned decimal (base 10) number.
// • %x Prints a number in hexadecimal (base 16) lowercase format.
// • %X Prints a number in hexadecimal (base 16) uppercase format.
// • %% Prints a percent sign.

#endif
