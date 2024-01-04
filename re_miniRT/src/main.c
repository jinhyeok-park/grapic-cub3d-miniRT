/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:25:08 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/04 19:54:01 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <sys/time.h>
// #include <stdio.h>
// #include <stdlib.h>
#include "miniRT.h"

void	free_parsing(t_input *input_data);

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;
}	t_mlx;

int	key_hook(int keycode, t_mlx *mlxs)
{
	if (keycode == 53)
	{
		printf("exit");
		exit(0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx		mlxs;
	void		*mlx_ptr;
	void		*win_ptr;
	t_data		img;
	t_input		input_data;
	t_ray		ray;
	t_scene		s;
	int			i;
	int			j;
	double		u;
	double		v;
	t_color3	test;

	mlx_ptr = mlx_init();
	mlxs.mlx_ptr = mlx_ptr;
	win_ptr = mlx_new_window(mlx_ptr, 1000, 800, "miniRT canvas");
	mlxs.win_ptr = win_ptr;
	img.img = mlx_new_image(mlx_ptr, 1000, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	parsing(ac, av, &input_data);
	scene_init1(&s, &input_data);
	j = s.canvas.height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < s.canvas.width)
		{
			u = (double)i / (s.canvas.width - 1);
			v = (double)j / (s.canvas.height - 1);
			ray = ray_primary(&(s.camera), u, v);
			s.ray = ray;
			test = ray_color(&s);
			write_color(test, &img, i, s.canvas.height - 1 - j);
			++i;
		}
		--j;
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	mlx_hook(win_ptr, 2, 0, key_hook, &mlxs);
	mlx_loop(mlx_ptr);
	free_parsing(&input_data);
}

void	free_parsing(t_input *input_data)
{
	free(input_data->light);
	free(input_data->sphere);
	free(input_data->plane);
	free(input_data->cylinder);
}
