/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:17:21 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/15 22:18:32by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minirt.h"
#include "vector.h"
#include "object.h"

void	my_mlx_line2d(void *mlx_ptr, void *win_ptr, int x0, int y0, int x1, int y1);

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

t_vec3 transform_point(t_vec3 point)
{
    t_vec3 transformed;
    double perspective = 500.0;

    transformed.x = point.x / (point.z + perspective);
    transformed.y = point.y / (point.z + perspective);
    transformed.z = 1;

    transformed.x = transformed.x * 400 + 400;
    transformed.y = -transformed.y * 400 + 300;

    return transformed;
}

#include <math.h>
#include "camera.h"
//#include "trace.h"
#include "trace.h"
#include <stdio.h>

void	my_mlx_line2d(void *mlx_ptr, void *win_ptr, int x0, int y0, int x1, int y1)
{
	int dx = x1 - x0;
    int dy = y1 - y0;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); // 더 긴 거리를 기준으로 단계 결정

    float x_inc = dx / (float)steps;
    float y_inc = dy / (float)steps;

    float x = x0;
    float y = y0;

    for (int i = 0; i <= steps; i++) {
        mlx_pixel_put(mlx_ptr, win_ptr, (int)round(x), (int)round(y), 0xFFFFFF); // 흰색 점으로 그리기
        x += x_inc;
        y += y_inc;
    }
}

void draw_line(void *mlx_ptr, void *win_ptr, t_vec3 p1, t_vec3 p2)
{
    t_vec3 tp1 = transform_point(p1);
    t_vec3 tp2 = transform_point(p2);

    my_mlx_line2d(mlx_ptr, win_ptr, tp1.x, tp1.y, tp2.x, tp2.y);
}

void write_color(t_color3 pixel_color, t_data *img, int x, int y) {
    // 각 색상 값을 [0, 255] 범위의 정수로 변환
    int ir = (int)(255.999 * pixel_color.r);
    int ig = (int)(255.999 * pixel_color.g);
    int ib = (int)(255.999 * pixel_color.b);

    int color;

    color = (ir << 16) | (ig << 8) |  ib;// to 32bit
    my_mlx_pixel_put(img, x, y, color);
}

// int	main(int ac, char **av)
// {
// 	// ft_printf("in here");
// 	// void	*mlx;
// 	// void	*mlx_window;
// 	// t_data	img;
	
// 	// mlx = mlx_init();
// 	// if (mlx == NULL)
// 	// {
// 	// 	ft_printf("mlx init error occur!");
// 	// 	return (1);
// 	// }
// 	// mlx_window = mlx_new_window(mlx, 1980, 1080, "miniRT");
// 	// if (mlx_window == NULL)
// 	// {
// 	// 	ft_printf("mlx new window error occur!");
// 	// 	return (1);
// 	// }
// 	// img.img = mlx_new_image(mlx, 1980, 1080);
// 	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	// 	for(int i = 0; i < 100 ; i++) {
// 	// 	// my_mlx_pixel_put(&img, i, i, 0x00FF0000);// 붉은색 선을 대각선으로 그린다.
// 	// 	my_mlx_pixel_put(&img, 985, 540 + i, 0x00FF0000);// 붉은색 선을 세로으로 그린다.
// 	// 	my_mlx_pixel_put(&img,985 + i, 540 , 0x00FF0000);// 붉은색 선을 가로으로 그린다.
// 	// }
// 	// mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);//이미지를 윈도우에 올린다.
// 	// mlx_loop(mlx);



// 	//     int     i;
//     // int     j;
//     // double  r;
//     // double  g;
//     // double  b;
//     // int     canvas_width;
//     // int     canvas_height;

//     // //캔버스의 가로, 세로 픽셀값
//     // canvas_width = 256;
//     // canvas_height = 256;

//     // // 랜더링
//     // // P3 는 색상값이 아스키코드라는 뜻, 그리고 다음 줄은 캔버스의 가로, 세로 픽셀 수, 마지막은 사용할 색상값
//     // ft_printf("P3\n%d %d\n255\n", canvas_width, canvas_height);
//     // j = canvas_height - 1;
//     // while (j >= 0)
//     // {
//     //     i = 0;
//     //     while (i < canvas_width)
//     //     {
//     //         r = (double)i / (canvas_width - 1);
//     //         g = (double)j / (canvas_height - 1);
//     //         b = 0.25;
//     //         ft_printf("%d %d %d\n", (int)(255.999 * r), (int)(255.999 * g), (int)(255.999 * b));
//     //     ++i;
//     //     }
//     // --j;
//     // }
//     // return (0);
//     void    *mlx_ptr;
//     void    *win_ptr;
//     t_data  img;
//     // void *win_ptr2;
//     // t_vec3 p1 = {100, 100, 5}; // 첫 번째 점 (3D)
//     // t_vec3 p2 = {200, 200, 300}; // 두 번째 점 (3D)

//     // // MiniLibX 초기화
//     mlx_ptr = mlx_init();
//     // // 첫 번째 윈도우 생성
//     win_ptr = mlx_new_window(mlx_ptr, 1980, 1080, "miniRT canvas");
// 	img.img = mlx_new_image(mlx_ptr, 1980, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

//     // // 두 번째 윈도우 생성
//     // win_ptr2 = mlx_new_window(mlx_ptr, 800, 600, "3D Line in 2D2");

//     // // 첫 번째 윈도우에 라인 그리기
//     // draw_line(mlx_ptr, win_ptr, p1, p2);

//     // // 두 번째 윈도우에 라인 그리기
//     // t_vec3 p3 = {100, 100, 5000}; // 첫 번째 점 (3D)
//     // t_vec3 p4 = {200, 200, 300}; // 두 번째 점 (3D)
//     // draw_line(mlx_ptr, win_ptr2, p3, p4);

//     // // 이벤트 루프 시작
//     // mlx_loop(mlx_ptr);

//     int         i;
//     int         j;
//     /* * * * 추가 * * * */
//     double      u;
//     double      v;
//     /* * * * 추가 끝 * * * */

//     t_color3    pixel_color;
//     /* * * * 수정 * * * */
//     t_canvas    canv;
//     t_camera    cam;
//     void        *temp_v;
//     t_ray       ray;
//     t_sphere    circle;
//     t_sphere    circle2;
//     t_sphere    circle3;
//     t_object    **obj_vector;

//     //Scene setting;
//     obj_vector = vector_create();
//     circle = sphere(point3(-2, 0, -15), 2);
//     circle2 = sphere(point3(2, 0, -15), 2);
//     circle3 = sphere(point3(0, -1000, 0), 994);
//     vector_push_back(obj_vector, (void*)&circle, CIRCLE);
//     vector_push_back(obj_vector, (void*)&circle2, CIRCLE);
//     vector_push_back(obj_vector, (void*)&circle3, CIRCLE);
//     canv = canvas(1980, 1080);
//     cam = camera(&canv, point3(0, 0, 0));
//     /* * * * 수정 끝 * * * */

//     // 랜더링
//     // P3 는 색상값이 아스키코드라는 뜻, 그리고 다음 줄은 캔버스의 가로, 세로 픽셀 수, 마지막은 사용할 색상값
//     /* * * * 수정 * * * */
//     // printf("P3\n%d %d\n255\n", canv.width, canv.height);
//     j = canv.height - 1;
//     /* * * * 수정 끝 * * * */
//     while (j >= 0)
//     {
//         i = 0;
//         while (i < canv.width)
//         {
//             u = (double)i / (canv.width - 1);
//             v = (double)j / (canv.height - 1);
//             ray = ray_primary(&cam, u, v);
//             // pixel_color = ray_color(&ray, &circle);
//             pixel_color = ray_color1(&ray, obj_vector);
//             write_color(pixel_color, &img, i, j );
//             ++i;
//         }
//         --j;
//     }
// 	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);//이미지를 윈도우에 올린다.
// 	mlx_loop(mlx_ptr);
// }

// int	main(int ac, char **av)
// {
//     void    *mlx_ptr;
//     void    *win_ptr;
//     t_data  img;
//     mlx_ptr = mlx_init();
//     win_ptr = mlx_new_window(mlx_ptr, 1980, 1080, "miniRT canvas");
// 	img.img = mlx_new_image(mlx_ptr, 1980, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

//     int         i;
//     int         j;
//     double      u;
//     double      v;

//     t_color3    pixel_color;
//     t_canvas    canv;
//     t_camera    cam;
//     void        *temp_v;
//     t_ray       ray;
//     t_sphere    circle;
//     t_sphere    circle2;
//     t_sphere    circle3;
//     t_object    **obj_vector;

//     obj_vector = vector_create();
//     circle = sphere(point3(-2, 0, -15), 2);
//     circle2 = sphere(point3(2, 0, -15), 2);
//     circle3 = sphere(point3(0, -1000, 0), 994);
//     vector_push_back(obj_vector, (void*)&circle, CIRCLE);
//     vector_push_back(obj_vector, (void*)&circle2, CIRCLE);
//     vector_push_back(obj_vector, (void*)&circle3, CIRCLE);
//     canv = canvas(1980, 1080);
//     cam = camera(&canv, point3(0, 0, 0));
//     j = canv.height - 1;
//     while (j >= 0)
//     {
//         i = 0;
//         while (i < canv.width)
//         {
//             u = (double)i / (canv.width - 1);
//             v = (double)j / (canv.height - 1);
//             ray = ray_primary(&cam, u, v);
//             pixel_color = ray_color1(&ray, obj_vector);
//             write_color(pixel_color, &img, i, j );
//             ++i;
//         }
//         --j;
//     }
// 	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
// 	mlx_loop(mlx_ptr);
// }

#include "scene.h"
//#include "parsing.h"

int	main(int ac, char **av)
{
    void    *mlx_ptr;
    void    *win_ptr;
    t_data  img;
    //t_input input_data;

    //parsing(ac, av, &input_data);
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 1980, 1080, "miniRT canvas");
	img.img = mlx_new_image(mlx_ptr, 1980, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    int         i;
    int         j;
    double      u;
    double      v;

    t_color3    pixel_color;
    t_ray       ray;
    t_scene     *s;
    void        *temp_v;
  
    s = scene_init3();
    j = s->canvas.height - 1;
    while (j >= 0)
    {
        i = 0;
        while (i < s->canvas.width)
        {
            u = (double)i / (s->canvas.width - 1);
            v = (double)j / (s->canvas.height - 1);
            s->ray = ray_primary(&(s->camera), u, v);
            pixel_color = ray_color2(s);
            write_color(pixel_color, &img, i, j );
            ++i;
        }
        --j;
    }
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	mlx_loop(mlx_ptr);
}
