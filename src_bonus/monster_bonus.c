/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:25:11 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/06/15 14:57:16 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_rand_move(t_game **game)
{
	int	direction;
	int	x;
	int	y;
	int	i;

	i = -1;
	while (++i < (*game)->enemy_count)
	{
		x = (*game)->enemy_position[i * 2];
		y = (*game)->enemy_position[i * 2 + 1];
		direction = get_random_number(4);
		background_set(x, y, game);
		if (direction == 0)
			enemy_move_position(x + 1, y, game, i);
		else if (direction == 1)
			enemy_move_position(x - 1, y, game, i);
		else if (direction == 2)
			enemy_move_position(x, y + 1, game, i);
		else if (direction == 3)
			enemy_move_position(x, y - 1, game, i);
	}
}

void	background_set(int x, int y, t_game **game)
{
	draw_img(x, y, (*game)->img_black, (*game));
	if ((*game)->map[y][x] == 'C')
		draw_img(x, y, (*game)->img_coin, (*game));
	else if ((*game)->map[y][x] == 'P')
		draw_img(x, y, (*game)->img_black, (*game));
	else if ((*game)->map[y][x] == 'E')
		draw_img(x, y, (*game)->img_portal, (*game));
}

void	enemy_move_position(int x, int y, t_game **game, int enemy_index)
{
	int	i;

	i = -1;
	if ((*game)->map[y][x] != '1')
	{
		(*game)->enemy_position[enemy_index * 2] = x;
		(*game)->enemy_position[enemy_index * 2 + 1] = y;
	}
	draw_img((*game)->enemy_position[enemy_index * 2], \
	(*game)->enemy_position[enemy_index * 2 + 1], (*game)->img_enemy, (*game));
}

void	monster_level(int steps, t_game **game)
{
	if (steps == 0 && (*game)->enemy_count == 0)
		enemy_random_generation(game);
	else if (steps == 100 && (*game)->enemy_count == 1)
		enemy_random_generation(game);
	else if (steps == 200 && (*game)->enemy_count == 2)
		enemy_random_generation(game);
	else if (steps == 300 && (*game)->enemy_count == 3)
		enemy_random_generation(game);
	else if (steps == 400 && (*game)->enemy_count == 4)
		enemy_random_generation(game);
}

void	enemy_random_generation(t_game **game)
{
	int	randx;
	int	randy;

	while (1)
	{
		randx = get_random_number((*game)->width);
		randy = get_random_number((*game)->height);
		if ((*game)->map[randy][randx] == '0')
		{
			(*game)->enemy_position[(*game)->enemy_count * 2] = randx;
			(*game)->enemy_position[(*game)->enemy_count * 2 + 1] = randy;
			(*game)->enemy_count++;
			break ;
		}
	}
}
