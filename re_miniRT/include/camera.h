/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:05:43 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/03 15:15:05 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vector3.h"

typedef struct s_camera
{
	t_point3	orig;
	double		viewport_h;
	double		viewport_w;
	t_vec3		horizontal;
	t_vec3		vertical;
	double		focal_len;
	t_point3	left_bottom;
	t_point3	dir;
	double		fov;
}	t_camera;

typedef struct s_canvas
{
	int		width;
	int		height;
	double	aspect_ratio;
}	t_canvas;

t_canvas	canvas(int width, int height);
t_camera	camera(t_canvas *canvas, t_point3 origin);

#endif
