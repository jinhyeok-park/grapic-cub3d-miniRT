/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:20:06 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/06 01:23:19 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_bool	hit_divide2(int index, t_scene *s, t_ray *ray, t_hit_record *local_rec)
{
	t_bool	hit;

	hit = FALSE;
	if (s->world[index]->type == CIRCLE)
	{
		if (hit_sphere((void *)s->world[index]->element, ray, local_rec))
			hit = TRUE;
	}
	else if (s->world[index]->type == PLANE)
	{
		if (hit_plane((void *)s->world[index]->element, ray, local_rec))
			hit = TRUE;
	}
	else if (s->world[index]->type == CYLINDER)
	{
		if (hit_cylinder((void *)s->world[index]->element, ray, local_rec))
			hit = TRUE;
	}
	return (hit);
}

t_bool	hit_divide(int index, t_scene *s, t_ray *ray, t_hit_record *rec)
{
	t_bool			hit;
	t_hit_record	local_rec;

	hit = FALSE;
	local_rec = record_init();
	if (hit_divide2(index, s, ray, &local_rec))
		hit = TRUE;
	if (hit && local_rec.t < rec->t)
	{
		rec->t = local_rec.t;
		rec->p = local_rec.p;
		rec->normal = local_rec.normal;
		rec->albedo.r = s->world[index]->albedo.r;
		rec->albedo.g = s->world[index]->albedo.g;
		rec->albedo.b = s->world[index]->albedo.b;
		return (TRUE);
	}
	return (FALSE);
}

t_color3	phong_lighting(t_scene *scene)
{
	t_color3	light_color;
	t_object	**lights;
	int			size;
	int			i;

	light_color = color3(0, 0, 0);
	lights = scene->light;
	i = 0;
	size = scene->light[0]->size;
	while (i < size)
	{
		if (scene->light[i]->type == LIGHT)
		{
			light_color = cplus(light_color, \
			point_light_get(scene, (t_light *)scene->light[i]->element));
		}
		i++;
	}
	light_color = cplus(light_color, scene->ambient);
	return (cmin(cmult_(light_color, scene->rec.albedo), color3(1, 1, 1)));
}
