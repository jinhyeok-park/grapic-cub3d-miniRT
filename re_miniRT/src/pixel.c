/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:36:07 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/19 15:43:53 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pixel.h"

void write_color(t_color3 pixel_color, t_data *img, int x, int y) 
{
    int ir = (int)(255.999 * pixel_color.r);
    int ig = (int)(255.999 * pixel_color.g);
    int ib = (int)(255.999 * pixel_color.b);

    int color;

    color = (ir << 16) | (ig << 8) |  ib;// to 32bit
    my_mlx_pixel_put(img, x, y, color);
}

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}