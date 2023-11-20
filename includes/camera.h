/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:06:18 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/11/17 17:06:50 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

#include "vector.h"

typedef struct	s_camera
{
	t_point3	camera_position;
	double		viewport_h;
	double		viewport_w;
	t_vec3		horiziontal_vec;
	t_vec3		vertical_vec;
	double		distance_camera_viewport;
	t_point3	left_bottom_p;
} t_camera;

typedef struct	s_canvas
{
	int	width;
	int	height;
	double	aspect_ratio; // ratio width hegiht;
} t_canvas;


t_canvas	canvas(int width, int height);
t_camera	camera(t_canvas *canvas, t_point3 origin);


#endif
