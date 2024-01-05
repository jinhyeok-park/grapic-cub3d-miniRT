/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:04:39 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/06 01:17:34 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	add_spheres(t_object **obj, t_input *input_data)
{
	t_sphere	*sp;
	int			i;

	i = 0;
	while (i < input_data->num_sp)
	{
		sp = sphere(input_data->sphere[i].center, input_data->sphere[i].radius);
		object_add(obj, sp, CIRCLE, input_data->sphere[i].color);
		i++;
	}
}

void	add_planes(t_object **obj, t_input *input_data)
{
	t_plane	*p;
	int		i;

	i = 0;
	while (i < input_data->num_pl)
	{
		p = plane(input_data->plane[i].point, input_data->plane[i].normal);
		object_add(obj, p, PLANE, input_data->plane[i].color);
		i++;
	}
}

void	add_cylinders(t_object **obj, t_input *input_data)
{
	t_cylinder	*cy;
	int			i;

	i = 0;
	while (i < input_data->num_cy)
	{
		cy = cylinder(input_data->cylinder[i].center, \
					input_data->cylinder[i].radius, \
					input_data->cylinder[i].height, \
					input_data->cylinder[i].normal);
		object_add(obj, cy, CYLINDER, input_data->cylinder[i].color);
		i++;
	}
}

void	add_lights(t_scene *s, t_object **lights, t_input *input_data)
{
	t_light	*li;
	int		i;

	i = 0;
	while (i < input_data->num_li)
	{
		li = light_point(input_data->light[i].origin, \
					input_data->light[i].light_color, \
					input_data->light[i].bright_ratio);
		object_add(lights, (void *)li, LIGHT, color3(0, 0, 0));
		i++;
	}
	s->light = lights;
}

void	scene_init1(t_scene *s, t_input *input_data)
{
	t_object	**obj;
	t_object	**lights;

	init_canvas_camera(s, input_data);
	create_objects_lights(s, input_data, &obj, &lights);
	add_spheres(obj, input_data);
	add_planes(obj, input_data);
	add_cylinders(obj, input_data);
	add_lights(s, lights, input_data);
}
