/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:03:40 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/06 01:23:10 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_ray	ray(t_point3 orig, t_vec3 dir)
{
	t_ray	ray;

	ray.orig = orig;
	ray.dir = vunit(dir);
	return (ray);
}

t_point3	ray_at(t_ray *ray, double t)
{
	t_point3	at;

	at = vplus(ray->orig, vmult(ray->dir, t));
	return (at);
}

t_ray	ray_primary(t_camera *cam, double u, double v)
{
	t_ray	ray;

	ray.orig = cam->orig;
	ray.dir = vunit(vminus(vplus(vplus(cam->left_bottom, \
	vmult(cam->horizontal, u)), vmult(cam->vertical, v)), cam->orig));
	return (ray);
}

t_color3	ray_color(t_scene *s)
{
	double	t;

	s->rec = record_init();
	if (hit(s, &(s->ray), &(s->rec)))
		return (phong_lighting(s));
	t = 0.5 * (s->ray.dir.y + 1.0);
	return (cplus(cmult(color3(1, 1, 1), 1.0 - t), \
	cmult(color3(0.5, 0.7, 1.0), t)));
}

t_bool	hit(t_scene *s, t_ray *ray, t_hit_record *rec)
{
	int		i;
	int		size;
	t_bool	hit;

	i = 0;
	hit = FALSE;
	if (s && s->world && s->world[0])
		size = s->world[0]->size;
	else
	{
		printf("please check again, objects are not inserted");
		exit(1);
	}
	while (i < size)
	{
		if (hit_divide(i, s, ray, rec))
			hit = TRUE;
		i++;
	}
	return (hit);
}
