/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:38:15 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/04 16:52:08 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int main(int ac, char **av)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1980, 1080, "miniRT canvas");
	img.img = mlx_new_image(mlx_ptr, 1980, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	mlx_loop(mlx_ptr);
}