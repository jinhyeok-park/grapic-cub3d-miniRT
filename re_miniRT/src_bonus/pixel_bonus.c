/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:36:07 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/06 01:17:37 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	write_color(t_color3 pixel_color, t_data *img, int x, int y)
{
	int	ir;
	int	ig;
	int	ib;
	int	color;

	ir = (int)(255.999 * pixel_color.r);
	ig = (int)(255.999 * pixel_color.g);
	ib = (int)(255.999 * pixel_color.b);
	color = (ir << 16) | (ig << 8) | ib;
	my_mlx_pixel_put(img, x, y, color);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
