/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:01:00 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/05 14:00:31 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "camera.h"
# include "object.h"
# include "color3.h"
# include "record.h"
# include "ray.h"
# include "light.h"
# include "parsing.h"

typedef struct s_scene
{
	t_canvas		canvas;
	t_camera		camera;
	t_object		**world;
	t_object		**light;
	t_color3		ambient;
	t_ray			ray;
	t_hit_record	rec;
}	t_scene;

void	scene_init(t_scene *s);
void	scene_init1(t_scene *s, t_input *input_data);
void	init_canvas_camera(t_scene *s, t_input *input_data);
void	create_objects_lights(t_scene *s, t_input *input_data, \
							t_object ***obj, t_object ***lights);

#endif