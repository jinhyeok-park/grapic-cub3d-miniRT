/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:08:34 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/06/20 13:16:49 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	count_coin(t_game **game, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
			{
				(*game)->collectable_coin++;
			}
		}
	}
	return ((*game)->collectable_coin);
}

int	is_surrounded(t_game **game, char **map)
{
	int	i;

	i = -1;
	while (++i < (*game)->width)
	{
		if (map[0][i] != '1')
			return (0);
	}
	i = -1;
	while (map[(*game)->height - 1][++i])
	{
		if (map[(*game)->height - 1][i] != '1')
			return (0);
	}
	i = 0;
	while (++i < (*game)->height)
	{
		if (map[i][0] != '1' || map[i][(*game)->width - 1] != '1')
			return (0);
	}
	return (1);
}

int	line_size_check(t_game **game, char **map)
{
	int	i;

	i = -1;
	while (map[++i])
	{
		if ((*game)->width != (int)ft_strlen2(map[i]))
			return (0);
	}
	return (1);
}

int	get_portal_pos(t_game **game, char **map)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'E')
				count++;
		}
	}
	if (count != 1)
		return (0);
	return (1);
}

int	get_player_pos(t_game **game, char **map)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
			{
				(*game)->player_position[0] = i;
				(*game)->player_position[1] = j;
				count++;
			}
		}
	}
	if (count != 1)
		return (0);
	return (1);
}
