/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:25:08 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/20 13:40:49 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int main(int ac, char **av)
{
    void    *mlx_ptr;
    void    *win_ptr;
    t_data  img;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 1000, 800, "miniRT canvas");
	img.img = mlx_new_image(mlx_ptr, 1000, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    
    t_canvas    canv;
    t_camera    cam;
    t_ray       ray;
    t_scene     s;

    canv = canvas(1000, 800);
    cam = camera(&canv, point3(0, 0, 0));

    int     i;
    int     j;
    double  u;
    double  v;
    double  r;
    double  g;
    double  b;

    scene_init(&s);
    t_color3 test;
    j = canv.height - 1;

    while (j >= 0)
    {
        i = 0;
        while (i < canv.width)
        {
            u = (double)i / (canv.width - 1);
            v = (double)j / (canv.height - 1);
            ray = ray_primary(&cam, u, v);
            // test = ray_color(&ray);
            //test = ray_color(&ray, obj);
            //printf("%d", s.world[0]->size);
            s.ray = ray;
            test = ray_color(&s);
            write_color(test, &img, i, canv.height - 1 - j);
            ++i;
        }
        --j;
    }
    mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	mlx_loop(mlx_ptr);
}