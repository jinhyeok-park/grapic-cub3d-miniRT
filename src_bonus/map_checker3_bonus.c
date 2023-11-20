/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker3_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:17:32 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/06/16 12:33:12 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	five_char(char c)
{
	int		i;
	char	arr[5];

	arr[0] = '0';
	arr[1] = '1';
	arr[2] = 'C';
	arr[3] = 'E';
	arr[4] = 'P';
	i = -1;
	while (++i < 5)
	{
		if (arr[i] == c)
			return (1);
	}
	return (0);
}

int	check_five_char(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!five_char(map[i][j]))
				return (0);
		}
	}
	return (1);
}

char	**visited_maker(t_game **game)
{
	char	**visited;
	int		i;

	i = -1;
	visited = (char **)malloc(sizeof(char *) * ((*game)->height + 1));
	if (!visited)
		return (0);
	visited[(*game)->height] = NULL;
	while (++i < (*game)->height)
	{
		visited[i] = (char *)malloc((*game)->width + 1);
		if (!visited[i])
		{
			free_map(visited, (*game)->height);
			return (0);
		}
	}
	init_map(visited, (*game)->height, (*game)->width);
	return (visited);
}
