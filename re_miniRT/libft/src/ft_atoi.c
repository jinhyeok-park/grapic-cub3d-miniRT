/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:53:09 by minjcho           #+#    #+#             */
/*   Updated: 2022/12/23 00:19:43 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	f_result(bool overflow, int sign, long nb)
{
	if (overflow == true && sign == 1)
		return (-1);
	else if (overflow == true && sign == -1)
		return (0);
	return (sign * nb);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;
	long	tmp;
	bool	flow;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		tmp = result * 10 + *str - '0';
		if (tmp < result)
			flow = true;
		result = tmp;
		str++;
	}
	return (f_result(flow, sign, result));
}
