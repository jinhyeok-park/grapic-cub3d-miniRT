/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:48:16 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/11/17 17:39:32 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_canvas    canvas(int width, int height)
{
    t_canvas canvas;

    canvas.width = width;
    canvas.height = height;
    canvas.aspect_ratio = (double)width / (double)height;
    return (canvas);
}

t_camera    camera(t_canvas *canvas, t_point3 origin)
{
    t_camera    ret;
    double      distance_camera_viewport;
    double      viewport_height;
    t_point3    temp;
    t_vec3      vectemp;
    t_vec3      vecz;

    viewport_height = 2.0;
    distance_camera_viewport = 1.0;
    ret.camera_position = origin;
    ret.viewport_h = viewport_height;
    ret.viewport_w = viewport_height * canvas->aspect_ratio;
    ret.distance_camera_viewport = distance_camera_viewport;
    ret.horiziontal_vec = vec3(ret.viewport_w, 0, 0);
    ret.vertical_vec = vec3(0, ret.viewport_h, 0);
    vecz = vec3(0, 0, ret.distance_camera_viewport);

    // divided = vec_divide_scala(&ret.horiziontal_vec, 2);
    // moved_point = point_move_minus(&(ret.camera_position), &divided);
    // moved_point = point_move_plus(&moved_point, &divided);
    vectemp = vec_divide_scala(&ret.horiziontal_vec, 2);
    temp = point_move_minus(&ret.camera_position, &vectemp);
    vectemp = vec_divide_scala(&ret.vertical_vec, 2);
    temp = point_move_plus(&temp, &vectemp);
    temp = point_move_minus(&temp, &vecz);
    ret.left_bottom_p = temp; // for test.
    return (ret);
}