/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:25:08 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/03 15:43:13 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <sys/time.h>
// #include <stdio.h>
// #include <stdlib.h>
#include "miniRT.h"

typedef struct s_mlx 
{
    void    *mlx_ptr;
    void    *win_ptr;
    t_data  img;
}	t_mlx;

int key_hook(int keycode, t_mlx *mlxs)
{
    if (keycode == 53)
    {
        printf("exit");
        exit(0);
    }
    //printf("%d\n", keycode);
    if (keycode == 13)
        printf("forward");
    else if (keycode == 0)
        printf("left move");
    else if (keycode == 1)
        printf("back");
    else if (keycode == 2)
        printf("right move");
    else if (keycode == 126)
        printf("up");
    else if (keycode == 123)
        printf("left");
    else if (keycode == 125)
        printf("down");
    else if (keycode == 124)
        printf("right");
    return (0);
}

int main(int ac, char **av)
{
    t_mlx   mlxs;
    void    *mlx_ptr;
    void    *win_ptr;
    t_data  img;
	t_input	input_data;

    mlx_ptr = mlx_init();
    mlxs.mlx_ptr = mlx_ptr;
    win_ptr = mlx_new_window(mlx_ptr, 1000, 800, "miniRT canvas");
    mlxs.win_ptr = win_ptr;
	img.img = mlx_new_image(mlx_ptr, 1000, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    
    t_ray       ray;
    t_scene     s;

    int     i;
    int     j;
    double  u;
    double  v;

	parsing(ac, av, &input_data);
	scene_init1(&s, &input_data);
    // scene_init(&s);
    t_color3 test;
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
    mlx_hook(win_ptr, 2,0, key_hook, &mlxs);
	mlx_loop(mlx_ptr);
}
