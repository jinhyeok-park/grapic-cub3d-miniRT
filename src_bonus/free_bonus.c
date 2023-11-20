/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:07:32 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/06/20 12:59:58 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_game(t_game **game)
{
	int	i;

	i = -1;
	free_map((*game)->map, (*game)->height);
	free((*game)->img_wall);
	free((*game)->img_black);
	free((*game)->img_coin);
	free((*game)->img_portal);
	while (++i < 8)
		free((*game)->img_player[i]);
	free((*game));
}

void	free_map(char **map, int height)
{
	int	i;

	if (map)
	{
		i = -1;
		while (++i < height)
		{
			free(map[i]);
		}
		free(map);
	}
}

void	free_split_char(char **map)
{
	int	i;

	if (map)
	{
		i = -1;
		while (map[++i])
			free(map[i]);
		free(map);
	}
}
