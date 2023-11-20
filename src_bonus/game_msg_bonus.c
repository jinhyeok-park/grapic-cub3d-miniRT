/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_msg_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:30:53 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/06/14 15:54:51 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	game_fin(t_game **game)
{
	ft_printf("_________game fin!! SUCCESS!!___________\n");
	ft_printf("Your Steps     : %d \n", (*game)->steps);
	ft_printf("Collected Coin : %d \n", (*game)->collected_coin);
	mlx_destroy_window((*game)->mlx, (*game)->mlx_window);
	free_game(game);
	exit(0);
}

void	game_defeat(t_game **game)
{
	ft_printf("___________MISSION_FAIL______________\n");
	ft_printf("Your Steps     : %d\n", (*game)->steps);
	ft_printf("Collected Coin : %d\n", (*game)->collected_coin);
	mlx_destroy_window((*game)->mlx, (*game)->mlx_window);
	free_game(game);
	exit(0);
}
