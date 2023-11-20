/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:09:47 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/06/20 12:43:43 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**map_checker(char **av, t_game **game, int fd)
{
	char	**ret;
	char	*line;
	char	*map;

	map = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == 0)
			break ;
		(*game)->height++;
		map = ft_strjoin_custom(map, line);
		if (!map)
		{
			free(line);
			return (NULL);
		}
		free(line);
	}
	if (!line && (*game)->height == 0)
		return (NULL);
	close(fd);
	ret = ft_split(map, '\n');
	free(map);
	return (map_checker_2(ret, game));
}

char	**map_checker_2(char **map, t_game **game)
{
	int	i;

	i = -1;
	(*game)->map = map;
	while (map[++i])
		(*game)->total_len += ft_strlen(map[i]);
	(*game)->width = (*game)->total_len / (*game)->height;
	if (!get_player_pos(game, map))
	{
		error_msg(1);
		return (0);
	}
	if (!get_portal_pos(game, map))
	{
		error_msg(2);
		return (0);
	}
	if (!line_size_check(game, map))
	{
		error_msg(3);
		return (0);
	}
	return (map_checker_3(map, game));
}

char	**map_checker_3(char **map, t_game **game)
{
	if (!is_surrounded(game, map))
	{
		error_msg(4);
		return (0);
	}
	if (!portal_accessible(map, game))
	{
		error_msg(6);
		return (0);
	}
	if (count_coin(game, map) < 1 || \
	(*game)->accessible_coin != (*game)->collectable_coin)
	{
		error_msg(5);
		return (0);
	}
	if (!check_five_char(map))
	{
		error_msg(7);
		return (0);
	}
	return (map);
}

int	portal_accessible(char **map, t_game **game)
{
	char	**visited;

	visited = visited_maker(game);
	dfs((*game)->player_position[1], (*game)->player_position[0], \
	visited, game);
	free_map(visited, (*game)->height);
	if ((*game)->is_accessible == 0)
		return (0);
	return (1);
}
