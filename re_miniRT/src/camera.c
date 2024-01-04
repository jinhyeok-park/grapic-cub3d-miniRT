/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:07:50 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/04 19:41:16 by minjcho          ###   ########.fr       */
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

t_camera	camera(t_canvas *canvas, t_point3 orig, double fov, t_vec3 direction)
{
	t_camera	cam;
	double		focal_len;
	double		viewport_height;
	double		theta;
	t_point3	look_at;
	t_vec3		vup;
	t_vec3		u;
	t_vec3		v;
	t_vec3		w;

	look_at = vplus(orig, vunit(direction));
	vup = vec3(0, 1, 0);
	focal_len = vlength(vminus(look_at, orig));
	w = vunit(vminus(orig, look_at));
	u = vunit(vcross(vup, w));
	v = vcross(w, u);
	theta = degrees_to_radians(fov) / 2;
	viewport_height = 2.0 * tan(theta);
	cam.viewport_h = viewport_height;
	cam.viewport_w = cam.viewport_h * canvas->aspect_ratio;
	cam.focal_len = focal_len;
	cam.horizontal = vmult(u, cam.viewport_w);
	cam.vertical = vmult(v, cam.viewport_h);
	cam.orig = orig;
	cam.left_bottom = vminus(vminus(vminus(orig, vdivide(cam.horizontal, 2)), vdivide(cam.vertical, 2)), w);
	return (cam);
}

double	degrees_to_radians(double degrees)
{
	return (degrees * (M_PI / 180.0));
}
