/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:06:44 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/06/20 12:31:43 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error_msg(int num)
{
	ft_printf("ERROR\n");
	if (num == 1)
		ft_printf("PLAYER_POSITION_ERROR\n");
	else if (num == 2)
		ft_printf("PORTAL_POSITION_ERROR\n");
	else if (num == 3)
		ft_printf("MAP_IS_NOT_RECTANGLE\n");
	else if (num == 4)
		ft_printf("MAP_IS_NOT_SURROUNDED_BY_WALL\n");
	else if (num == 5)
		ft_printf("COIN_COUNT_IS_NOT_ENOUGH\n");
	else if (num == 6)
		ft_printf("NO_WAY_TO_PORTAL\n");
	else if (num == 7)
		ft_printf("MAP_HAS_A_NOT_INCLUDED_CHARACTER\n");
	else if (num == 8)
		ft_printf("FILE_ERROR\n");
}
