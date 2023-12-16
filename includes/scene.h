/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:54:41 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/16 00:48:06 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "object.h"
#include "ray.h"
#include "hit_record.h"


typedef struct s_scene
{
	t_canvas        canvas;
	t_camera        camera;
	t_object        **world;
	t_object        **light;
	t_color3        ambient;
	t_hit_record    rec;
	t_ray			ray;
} t_scene;

t_scene	*scene_init3(void);

#endif