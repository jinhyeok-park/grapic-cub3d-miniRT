/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:23:27 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/06/14 15:54:16 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	steps_display(t_game **game)
{
	char	*temp_1;
	char	*temp_2;

	temp_1 = ft_itoa((*game)->steps - 1);
	temp_2 = ft_itoa((*game)->steps);
	mlx_string_put((*game)->mlx, (*game)->mlx_window, \
	((*game)->width / 2 - 3) * 32, ((*game)->height + 1) * 32, \
	0xFFFFFF, "steps : ");
	mlx_string_put((*game)->mlx, (*game)->mlx_window, \
	((*game)->width / 2) * 32, ((*game)->height + 1) * 32, \
	0x000000, temp_1);
	mlx_string_put((*game)->mlx, (*game)->mlx_window, \
	((*game)->width / 2) * 32, ((*game)->height + 1) * 32, \
	0xFFFFFF, temp_2);
	free(temp_1);
	free(temp_2);
}
