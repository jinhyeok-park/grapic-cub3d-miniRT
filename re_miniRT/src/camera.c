/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:07:50 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/06 00:55:20 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_canvas	canvas(int width, int height)
{
	t_canvas	canvas;

	canvas.width = width;
	canvas.height = height;
	canvas.aspect_ratio = (double)width / (double)height;
	return (canvas);
}

t_camera_helper	init_camera_helper(t_point3 orig, t_vec3 direction)
{
	t_camera_helper	helper;

	helper.look_at = vplus(orig, vunit(direction));
	helper.vup = vec3(0, 1, 0);
	helper.w = vunit(vminus(orig, helper.look_at));
	helper.u = vunit(vcross(helper.vup, helper.w));
	helper.v = vcross(helper.w, helper.u);
	return (helper);
}

t_camera	camera(t_canvas *canvas, t_point3 orig, double fov, \
				t_vec3 direction)
{
	t_camera		cam;
	double			focal_len;
	double			viewport_height;
	double			theta;
	t_camera_helper	helper;

	helper = init_camera_helper(orig, direction);
	focal_len = vlength(vminus(helper.look_at, orig));
	theta = degrees_to_radians(fov) / 2;
	viewport_height = 2.0 * tan(theta);
	cam.viewport_h = viewport_height;
	cam.viewport_w = cam.viewport_h * canvas->aspect_ratio;
	cam.focal_len = focal_len;
	cam.horizontal = vmult(helper.u, cam.viewport_w);
	cam.vertical = vmult(helper.v, cam.viewport_h);
	cam.orig = orig;
	cam.left_bottom = vminus(vminus(vminus(orig, vdivide(cam.horizontal, 2)), \
					vdivide(cam.vertical, 2)), helper.w);
	return (cam);
}

double	degrees_to_radians(double degrees)
{
	return (degrees * (M_PI / 180.0));
}
