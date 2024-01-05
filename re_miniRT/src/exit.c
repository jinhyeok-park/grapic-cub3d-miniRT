/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:19:38 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/05 16:21:47 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
