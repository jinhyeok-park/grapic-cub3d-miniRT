/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:16:04 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/06/16 12:29:18 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	dfs(int x, int y, char **visited, t_game **game)
{
	int	i;

	i = -1;
	visited[x][y] = '1';
	if ((*game)->map[x][y] == 'C')
		(*game)->accessible_coin++;
	if ((*game)->map[x][y] == 'E')
		(*game)->is_accessible = 1;
	while (++i < 4)
	{
		if ((*game)->map[x][y + 1] != '1' && visited[x][y + 1] != '1')
			dfs(x, y + 1, visited, game);
		if ((*game)->map[x][y - 1] != '1' && visited[x][y - 1] != '1')
			dfs(x, y - 1, visited, game);
		if ((*game)->map[x + 1][y] != '1' && visited[x + 1][y] != '1')
			dfs(x + 1, y, visited, game);
		if ((*game)->map[x - 1][y] != '1' && visited[x - 1][y] != '1')
			dfs(x - 1, y, visited, game);
	}
}
