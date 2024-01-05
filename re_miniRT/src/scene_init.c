/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:58:27 by minjcho           #+#    #+#             */
/*   Updated: 2024/01/05 14:00:14 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	init_canvas_camera(t_scene *s, t_input *input_data)
{
	s->canvas = canvas(1000, 800);
	s->camera = camera(&(s->canvas), input_data->cam.orig, \
						input_data->cam.fov, input_data->cam.dir);
}

void	create_objects_lights(t_scene *s, t_input *input_data, \
							t_object ***obj, t_object ***lights)
{
	*obj = create_object(input_data->total_object);
	*lights = create_object(input_data->num_li);
	s->world = *obj;
	s->light = NULL;
	s->ambient = input_data->ambient;
}
