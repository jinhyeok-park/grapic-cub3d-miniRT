/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:37:49 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/06/20 13:07:17 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
	{
		error_msg(8);
		exit(1);
	}
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (0);
	checker(&game, av);
	map_init1(&game);
	game_start(&game);
	return (0);
}

void	checker(t_game **game, char **av)
{
	char	**map;
	int		fd;

	map_init_size(game);
	fd = open(av[1], O_RDONLY);
	if (fd == -1 || !type_checker(av[1]))
	{
		error_msg(8);
		free_game(game);
		exit(1);
	}
	map = map_checker(av, game, fd);
	if (!map)
	{
		if ((*game)->height == 0)
			error_msg(3);
		free_game(game);
		exit(1);
	}
}

int	type_checker(char *s)
{
	char	**temp;
	char	*ber;
	int		i;
	int		last;

	temp = ft_split(s, '.');
	ber = "ber";
	i = -1;
	last = 0;
	while (temp[++i])
		last++;
	last--;
	i = -1;
	while (++i < 3)
	{
		if (temp[last][i] != ber[i])
		{
			free_split_char(temp);
			return (0);
		}
	}
	free_split_char(temp);
	return (1);
}
