/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:12:31 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/06/15 15:50:30 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_init_size(t_game **game)
{
	(*game)->height = 0;
	(*game)->width = 0;
	(*game)->is_accessible = 0;
	(*game)->total_len = 0;
	(*game)->steps = 0;
	(*game)->collectable_coin = 0;
	(*game)->collected_coin = 0;
	(*game)->accessible_coin = 0;
	(*game)->player_direction = -1;
	(*game)->frame = -1;
	(*game)->enemy_frame = -1;
	(*game)->enemy_count = 0;
	(*game)->is_defeat = 0;
	(*game)->map = NULL;
	(*game)->mlx = NULL;
	(*game)->mlx_window = NULL;
	(*game)->img_wall = NULL;
	(*game)->img_black = NULL;
	(*game)->img_coin = NULL;
	(*game)->img_portal = NULL;
	(*game)->img_player[0] = NULL;
	(*game)->img_player[1] = NULL;
	(*game)->img_player[2] = NULL;
	(*game)->img_player[3] = NULL;
	init_img2(game);
}

void	init_img2(t_game **game)
{
	(*game)->img_player[4] = NULL;
	(*game)->img_player[5] = NULL;
	(*game)->img_player[6] = NULL;
	(*game)->img_player[7] = NULL;
	(*game)->img_die = NULL;
	(*game)->img_enemy = NULL;
	(*game)->enemy_found = 0;
}

void	map_init1(t_game **game)
{
	(*game)->mlx = mlx_init();
	(*game)->mlx_window = mlx_new_window((*game)->mlx, (*game)->width * 32, \
	((*game)->height + 2) * 32, "pac-man-bonus");
}

void	init_map(char **map, int height, int width)
{
	int	i;
	int	j;

	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
		{
			map[i][j] = '0';
		}
	}
}
