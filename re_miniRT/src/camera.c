/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:07:50 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/04 14:31:10 by jinhyeok         ###   ########.fr       */
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
//t_camera	camera(t_canvas *canvas, t_point3 orig, double fov)
t_camera	camera(t_canvas *canvas, t_point3 orig, double fov, t_vec3 direction)
{
	t_camera	cam;
	double		focal_len;
	double		viewport_height;
	double		theta;
	t_point3	look_from;
	t_point3	look_at;
	t_vec3		vup;
	t_vec3		u;
	t_vec3		v;
	t_vec3		w;

	//direction is normal;
	look_from = orig;
	// printf("origin : %f ", orig.x);
	// printf("%f ", orig.y);
	// printf("%f\n", orig.z);
	look_at = vplus(orig, vunit(direction));
	// printf("look at : %f ", look_at.x);
	// printf("%f ", look_at.y);
	// printf("%f\n", look_at.z);
	vup = vec3(0,1,0);
	cam.orig = look_from;
	focal_len = vlength((look_from, look_at));
	w = vunit(vminus(look_from, look_at));
	// printf("w %f ", w.x);
	// printf("%f ", w.y);
	// printf("%f\n", w.z);
	u = vunit(vcross(vup, w)); // error occur
	v = vcross(w, u);
	
	//focal_len = 1.0;
	cam.orig = orig;
	viewport_height = 2.0;
	theta = degrees_to_radians(fov);
	theta = tan(theta / 2);
	cam.viewport_h = 2 * theta * focal_len;
	cam.viewport_w = cam.viewport_h * canvas->aspect_ratio;
	cam.focal_len = focal_len;
	//cam.horizontal = vec3(cam.viewport_w, 0, 0);
	cam.horizontal = vmult(u, cam.viewport_w);
	//cam.vertical = vec3(0, cam.viewport_h, 0);
	cam.vertical = vmult(v, cam.viewport_h);
	cam.left_bottom = vminus(vminus \
	(vminus(cam.orig, vdivide(cam.horizontal, 2)), \
	vdivide(cam.vertical, 2)), vec3(0, 0, focal_len));
	return (cam);
}

double	degrees_to_radians(double degrees)
{
	return (degrees * (M_PI / 180.0));
}
