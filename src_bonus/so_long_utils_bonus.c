/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:13:25 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/06/14 16:01:38 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_img(int y, int x, void *img, t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_window, img, y * 32, x * 32);
}

char	*ft_strjoin_custom(char *s1, char *s2)
{
	int		s1l;
	int		s2l;
	char	*result;

	s1l = ft_strlen2(s1);
	s2l = ft_strlen2(s2);
	result = (char *)malloc(s1l + s2l + 1);
	if (!result)
		return (0);
	result[0] = 0;
	if (s1l == 0)
	{
		free(result);
		return (ft_strdup(s2));
	}
	ft_strlcat(result, (char *)s1, s1l + 1);
	ft_strlcat(result, (char *)s2, s1l + s2l + 1);
	free(s1);
	return (result);
}

int	close_window(t_game **game)
{
	mlx_destroy_window((*game)->mlx, (*game)->mlx_window);
	free_game(game);
	exit(0);
}

void	to_black(int x, int y, t_game *game)
{
	if (game->map[x][y] == 'E')
	{
		draw_img(game->player_position[1], game->player_position[0], \
		game->img_portal, game);
	}
	else if (game->map[x][y] != 'E')
	{
		draw_img(game->player_position[1], game->player_position[0], \
		game->img_black, game);
	}
}
