/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:11:22 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/06/16 12:30:51 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	game_start(t_game **game)
{
	srand((unsigned int)time(NULL));
	mlx_hook((*game)->mlx_window, 2, 0, player_direction, game);
	mlx_hook((*game)->mlx_window, 17, 0, close_window, game);
	img_load(game);
	draw_map((*game));
	mlx_loop_hook((*game)->mlx, game_loop, game);
	mlx_loop((*game)->mlx);
}

int	game_loop(t_game **game)
{
	if ((*game)->is_defeat == 0)
	{
		monster_level((*game)->steps, game);
		if ((*game)->frame == 0)
			player_move_bo(game);
		else if ((*game)->frame == 1000)
			player_move_bo(game);
		if ((*game)->enemy_frame == 0)
			enemy_rand_move(game);
		collision_checker(game);
	}
	else
		is_over(game);
	(*game)->frame++;
	(*game)->enemy_frame++;
	if ((*game)->enemy_frame == 8000)
		(*game)->enemy_frame = 0;
	if ((*game)->frame == 2000)
		(*game)->frame = 0;
	return (0);
}

void	is_over(t_game **game)
{
	draw_img((*game)->player_position[1], \
		(*game)->player_position[0], (*game)->img_black, (*game));
	draw_img((*game)->player_position[1], \
		(*game)->player_position[0], (*game)->img_die, (*game));
	if ((*game)->frame % 100 == 0)
		game_defeat(game);
}

void	collision_checker(t_game **game)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	while (++i < (*game)->enemy_count)
	{
		x = (*game)->enemy_position[i * 2];
		y = (*game)->enemy_position[i * 2 + 1];
		if ((*game)->player_position[1] == x && \
		(*game)->player_position[0] == y)
			(*game)->is_defeat = 1;
	}
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == '1')
				draw_img(j, i, game->img_wall, game);
			if (game->map[i][j] == 'E')
				draw_img(j, i, game->img_portal, game);
			if (game->map[i][j] == 'C')
				draw_img(j, i, game->img_coin, game);
			if (game->map[i][j] == '0' || game->map[i][j] == 'P')
				draw_img(j, i, game->img_black, game);
		}
	}
	draw_img(game->player_position[1], game->player_position[0], \
	game->img_player[1], game);
}
