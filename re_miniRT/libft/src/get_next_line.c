/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:25:20 by minjcho           #+#    #+#             */
/*   Updated: 2023/02/21 16:17:42 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_next(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*new_result;
	size_t	i;
	size_t	j;

	new_result = (char *)ft_calloc((ft_strlen_next(s1)
				+ ft_strlen_next(s2) + 1), sizeof(char));
	if (!new_result)
		return (0);
	i = -1;
	while (s1[++i])
		new_result[i] = s1[i];
	j = -1;
	while (s2[++j])
		new_result[i + j] = s2[j];
	free(s1);
	free(s2);
	return (new_result);
}

char	*make_line(char *buf, char *result)
{
	const size_t	len = ft_strlen_next(buf);
	char			*tmp;
	char			*new_result;

	tmp = (char *)ft_calloc((len + 1), sizeof(char));
	if (!tmp)
		return (0);
	ft_memmove(tmp, buf, len);
	ft_memmove(buf, buf + len, BUFFER_SIZE - len);
	ft_bzero(buf + BUFFER_SIZE - len, len);
	new_result = ft_strjoin_free(result, tmp);
	return (new_result);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*result;
	int			read_result;

	if (fd < 0)
		return (0);
	result = (char *)ft_calloc(1, sizeof(char));
	if (!result)
		return (0);
	while (!ft_strchr(result, '\n'))
	{
		if (!buf[0])
		{
			read_result = read(fd, buf, BUFFER_SIZE);
			if (read_result == 0 && result[0] != 0)
				return (result);
			else if ((read_result < 0) || (!read_result && !result[0]))
			{
				free(result);
				return (0);
			}
		}
		result = make_line(buf, result);
	}
	return (result);
}
