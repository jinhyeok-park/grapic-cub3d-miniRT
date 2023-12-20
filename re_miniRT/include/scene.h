/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:01:00 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/12/20 14:46:05 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "object.h"
#include "color3.h"
#include "record.h"
#include "ray.h"
#include "light.h"


typedef struct s_scene
{
    t_canvas        canvas;
    t_camera        camera;
    t_object        **world;
    t_object        **light;
    t_color3        ambient;
    t_ray           ray;
    t_hit_record    rec;
} t_scene;

void    scene_init(t_scene *s);

#endif