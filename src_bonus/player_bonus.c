/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:29:02 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/06/20 13:18:02 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_move_bo(t_game **game)
{
	int	x;
	int	y;

	x = (*game)->player_position[0];
	y = (*game)->player_position[1];
	if ((*game)->player_direction == 3)
	{
		to_black(x, y, (*game));
		move_position(x - 1, y, game);
	}
	if ((*game)->player_direction == 2)
	{
		to_black(x, y, (*game));
		move_position(x + 1, y, game);
	}
	if ((*game)->player_direction == 1)
	{
		to_black(x, y, (*game));
		move_position(x, y - 1, game);
	}
	if ((*game)->player_direction == 0)
	{
		to_black(x, y, (*game));
		move_position(x, y + 1, game);
	}
}

int	player_direction(int keycode, t_game **game)
{
	if (keycode == 53)
	{
		mlx_destroy_window((*game)->mlx, (*game)->mlx_window);
		free_game(game);
		exit(0);
	}
	if (keycode == 13)
		(*game)->player_direction = 3;
	if (keycode == 1)
		(*game)->player_direction = 2;
	if (keycode == 0)
		(*game)->player_direction = 1;
	if (keycode == 2)
		(*game)->player_direction = 0;
	return (0);
}

void	move_position(int x, int y, t_game **game)
{
	if ((*game)->map[x][y] != '1')
	{
		(*game)->player_position[0] = x;
		(*game)->player_position[1] = y;
		(*game)->steps++;
		steps_display(game);
	}
	if ((*game)->map[x][y] == 'C')
	{
		(*game)->collectable_coin--;
		(*game)->collected_coin++;
		(*game)->map[x][y] = '0';
	}
	if ((*game)->collectable_coin == 0 && (*game)->map[x][y] == 'E')
	{
		draw_img((*game)->player_position[1], (*game)->player_position[0], \
		(*game)->img_player[0], (*game));
		game_fin(game);
	}
	draw_player_img((*game)->player_direction, (*game));
}

void	draw_player_img(int direction, t_game *game)
{
	if (game->frame == 0)
		draw_img(game->player_position[1], game->player_position[0], \
		game->img_player[2 * direction], game);
	else if (game->frame == 1000)
		draw_img(game->player_position[1], game->player_position[0], \
		game->img_player[2 * direction + 1], game);
}
