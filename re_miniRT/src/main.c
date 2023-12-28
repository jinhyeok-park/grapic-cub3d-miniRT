/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:25:08 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/27 14:10:24 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <sys/time.h>
// #include <stdio.h>
// #include <stdlib.h>
#include "miniRT.h"

// unsigned int gettime()
// {
//     struct timeval  time;

//     gettimeofday(&time, NULL);
//     return (time.tv_sec * 1000 + time.tv_usec / 1000);
// }

int main(int ac, char **av)
{
    void    *mlx_ptr;
    void    *win_ptr;
    t_data  img;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 1000, 800, "miniRT canvas");
	img.img = mlx_new_image(mlx_ptr, 1000, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    
    t_ray       ray;
    t_scene     s;

    int     i;
    int     j;
    double  u;
    double  v;

    scene_init(&s);
    t_color3 test;
    j = s.canvas.height - 1;
    
    // unsigned int time = gettime();
    while (j >= 0)
    {
        i = 0;
        while (i < s.canvas.width)
        {
            u = (double)i / (s.canvas.width - 1);
            v = (double)j / (s.canvas.height - 1);
            ray = ray_primary(&(s.camera), u, v);
            // test = ray_color(&ray);
            //test = ray_color(&ray, obj);
            //printf("%d", s.world[0]->size);
            s.ray = ray;
            test = ray_color(&s);
            write_color(test, &img, i, s.canvas.height - 1 - j);
            ++i;
        }
        --j;
    }
    mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
    //printf("Delta Time : %d\n", gettime() - time);
	mlx_loop(mlx_ptr);
}
