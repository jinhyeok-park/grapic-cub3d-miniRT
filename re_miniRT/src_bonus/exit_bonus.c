/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:19:38 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/06 01:17:48 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

int	key_hook(int keycode)
{
	if (keycode == 53)
	{
		printf("exit\n");
		exit(0);
	}
	return (0);
}

int	close_window(int keycode)
{
	(void)keycode;
	printf("exit\n");
	exit(0);
}
