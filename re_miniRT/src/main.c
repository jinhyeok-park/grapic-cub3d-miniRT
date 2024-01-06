/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:25:08 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/06 19:01:56 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_graphics(t_mlx *mlxs, t_data *img)
{
	mlxs->mlx_ptr = mlx_init();
	mlxs->win_ptr = mlx_new_window(mlxs->mlx_ptr, 1000, 800, "miniRT canvas");
	img->img = mlx_new_image(mlxs->mlx_ptr, 1000, 800);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
								&img->line_length, &img->endian);
}

void	process_scene(t_scene *s, int ac, char **av, t_input *input_data)
{
	parsing(ac, av, input_data);
	scene_init(s, input_data);
}

void	render_loop(t_mlx *mlxs, t_data *img, t_scene *s)
{
	int			i;
	int			j;
	t_ray		ray;
	t_color3	test;

	j = s->canvas.height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < s->canvas.width)
		{
			ray = ray_primary(&(s->camera), \
							(double)i / (s->canvas.width - 1), \
							(double)j / (s->canvas.height - 1));
			s->ray = ray;
			test = ray_color(s);
			write_color(test, img, i, s->canvas.height - 1 - j);
			i++;
		}
		j--;
	}
	mlx_put_image_to_window(mlxs->mlx_ptr, mlxs->win_ptr, img->img, 0, 0);
}

void	free_all(t_input *input_data, t_scene *s)
{
	int	i;

	i = -1;
	free(input_data->light);
	free(input_data->sphere);
	free(input_data->plane);
	free(input_data->cylinder);
	while (++i < input_data->num_li)
		free(s->light[i]);
	free(s->light);
	while (++i < input_data->total_object)
		free(s->world[i]);
	free(s->world);
}

int	main(int ac, char **av)
{
	t_mlx	mlxs;
	t_data	img;
	t_input	input_data;
	t_scene	s;

	init_graphics(&mlxs, &img);
	process_scene(&s, ac, av, &input_data);
	render_loop(&mlxs, &img, &s);
	mlx_hook(mlxs.win_ptr, 2, 0, key_hook, NULL);
	mlx_hook(mlxs.win_ptr, 17, 0, close_window, NULL);
	mlx_loop(mlxs.mlx_ptr);
	free_all(&input_data, &s);
	return (0);
}
