/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:07:50 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/03 16:48:55 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_canvas	canvas(int width, int height)
{
	t_canvas	canvas;

	canvas.width = width;
	canvas.height = height;
	canvas.aspect_ratio = (double)width / (double)height;
	return (canvas);
}

//t_camera    camera(t_canvas *canvas, t_point3 orig)
t_camera	camera(t_canvas *canvas, t_point3 orig, double fov)
{
	t_camera	cam;
	double		focal_len;
	double		viewport_height;
	double		theta;

	focal_len = 1.0;
	cam.orig = orig;
	viewport_height = 2.0;
	theta = degrees_to_radians(fov);
	theta = tan(theta / 2);
	cam.viewport_h = 2 * theta * focal_len;
	cam.viewport_w = cam.viewport_h * canvas->aspect_ratio;
	cam.focal_len = focal_len;
	cam.horizontal = vec3(cam.viewport_w, 0, 0);
	cam.vertical = vec3(0, cam.viewport_h, 0);
	cam.left_bottom = vminus(vminus \
	(vminus(cam.orig, vdivide(cam.horizontal, 2)), \
	vdivide(cam.vertical, 2)), vec3(0, 0, focal_len));
	return (cam);
}

double	degrees_to_radians(double degrees)
{
	return (degrees * (M_PI / 180.0));
}
