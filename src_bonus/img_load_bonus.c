/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_load_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:27:57 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/06/14 15:58:49 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	img_load(t_game **game)
{
	int	img_width;
	int	img_height;

	(*game)->img_wall = mlx_xpm_file_to_image((*game)->mlx, \
	"./textures/wall.xpm", &img_width, &img_height);
	(*game)->img_portal = mlx_xpm_file_to_image((*game)->mlx, \
	"./textures/portal.xpm", &img_width, &img_height);
	(*game)->img_coin = mlx_xpm_file_to_image((*game)->mlx, \
	"./textures/coin.xpm", &img_width, &img_height);
	(*game)->img_black = mlx_xpm_file_to_image((*game)->mlx, \
	"./textures/black.xpm", &img_width, &img_height);
	(*game)->img_enemy = mlx_xpm_file_to_image((*game)->mlx, \
	"./textures/enemy.xpm", &img_width, &img_height);
	(*game)->img_die = mlx_xpm_file_to_image((*game)->mlx, \
	"./textures/die.xpm", &img_width, &img_height);
	player_img_load(game);
}

void	player_img_load(t_game **game)
{
	int	img_width;
	int	img_height;

	(*game)->img_player[0] = mlx_xpm_file_to_image((*game)->mlx, \
	"./textures/pack_right_open.xpm", &img_width, &img_height);
	(*game)->img_player[1] = mlx_xpm_file_to_image((*game)->mlx, \
	"./textures/pack_right_half.xpm", &img_width, &img_height);
	(*game)->img_player[2] = mlx_xpm_file_to_image((*game)->mlx, \
	"./textures/pack_left_open.xpm", &img_width, &img_height);
	(*game)->img_player[3] = mlx_xpm_file_to_image((*game)->mlx, \
	"./textures/pack_left_half.xpm", &img_width, &img_height);
	(*game)->img_player[4] = mlx_xpm_file_to_image((*game)->mlx, \
	"./textures/pack_down_open.xpm", &img_width, &img_height);
	(*game)->img_player[5] = mlx_xpm_file_to_image((*game)->mlx, \
	"./textures/pack_down_half.xpm", &img_width, &img_height);
	(*game)->img_player[6] = mlx_xpm_file_to_image((*game)->mlx, \
	"./textures/pack_up_open.xpm", &img_width, &img_height);
	(*game)->img_player[7] = mlx_xpm_file_to_image((*game)->mlx, \
	"./textures/pack_up_half.xpm", &img_width, &img_height);
}
