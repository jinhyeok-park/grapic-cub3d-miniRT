/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:04:39 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/04 20:04:04 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "sphere.h"
#include "light.h"
#include "plane.h"
#include "cylinder.h"

void	scene_init1(t_scene *s, t_input *input_data)
{
	t_object	**obj;
	t_object	**lights;
	t_light		*li;
	t_sphere	*sp;
	t_plane		*p;
	t_cylinder	*cy;
	t_vec3		temp;
	int			i;

	i = 0;
	s->canvas = canvas(1000, 800);
	s->camera = camera(&(s->canvas), input_data->cam.orig, input_data->cam.fov, input_data->cam.dir);
	obj = create_object();
	lights = create_object();
	s->world = obj;
	s->light = NULL;
	s->ambient = input_data->ambient;
	while (i < input_data->num_sp)
	{
		sp = sphere(input_data->sphere[i].center, input_data->sphere[i].radius);
		object_add(obj, sp, CIRCLE, input_data->sphere[i].color);
		i++;
	}
	i = 0;
	while (i < input_data->num_pl)
	{
		p = plane(input_data->plane[i].point, input_data->plane[i].normal);
		object_add(obj, p, PLANE, input_data->plane[i].color);
		i++;
	}
	i = 0;
	while (i < input_data->num_cy)
	{
		cy = cylinder(input_data->cylinder[i].center, input_data->cylinder[i].radius, input_data->cylinder[i].height, input_data->cylinder[i].normal);
		object_add(obj, cy, CYLINDER, input_data->cylinder[i].color);
		i++;
	}
	i = 0;
	while (i < input_data->num_li)
	{
		li = light_point(input_data->light[i].origin, color3(1, 1, 1), input_data->light[i].bright_ratio);
		object_add(lights, (void *)li, LIGHT, color3(0, 0, 0));
		i++;
	}
	s->light = lights;
}
