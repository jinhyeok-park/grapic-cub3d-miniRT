/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:57:30 by minjcho           #+#    #+#             */
/*   Updated: 2022/12/22 20:16:05 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*tmp;

	i = -1;
	tmp = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!tmp)
		return (0);
	while (s[++i])
		tmp[i] = f(i, s[i]);
	tmp[i] = '\0';
	return (tmp);
}
