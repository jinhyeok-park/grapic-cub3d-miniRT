/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:21:24 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/03 13:25:24 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"
#include "sphere.h"
#include "plane.h"
#include "cylinder.h"
#include "light.h"


t_color3	point_light_get(t_scene *s, t_light *light)
{
	t_color3	diffuse;
	t_vec3		light_dir;
	t_color3	specular;
	double		brightness;

	if (is_shadow(s, light))
		return (color3(0, 0, 0));
	light_dir = vunit(vminus(light->origin, s->rec.p));
	diffuse = diffus_get(s, light_dir, light);
	specular = specular_get(s, light, light_dir);
	brightness = light->bright_ratio * 3;
	return (cmult(cplus(diffuse, specular), brightness));
}

t_color3	diffus_get(t_scene *s, t_vec3 light_dir, t_light *light)
{
	t_color3	diffuse;
	double		kd;

	kd = fmax(vdot(s->rec.normal, light_dir), 0.0);
	diffuse = cmult(light->light_color, kd);
	return (diffuse);
}

t_color3	specular_get(t_scene *s, t_light *light, t_vec3 light_dir)
{
	t_color3	specular;
	t_vec3		view_dir;
	t_vec3		reflect_dir;
	double		spec;
	double		k;

	k = KSN;
	reflect_dir = reflect(vmult(light_dir, -1), s->rec.normal);
	view_dir = vunit(vmult(s->ray.dir, -1));
	spec = pow(fmax(vdot(view_dir, reflect_dir), 0.0), k);
	k = KS;
	specular = cmult(cmult(light->light_color, k), spec);
	return (specular);
}

t_bool	is_shadow(t_scene *s, t_light *light)
{
	t_vec3			light_dir;
	double			light_len;
	t_ray			light_ray;
	t_hit_record	light_rec;

	light_dir = vminus(light->origin, s->rec.p);
	light_len = vlength(light_dir);
	light_dir = vunit(light_dir);
	light_ray = ray(vplus(s->rec.p, \
	vmult(s->rec.normal, 0.01)), light_dir);
	light_rec.tmin = EPYS;
	light_rec.t = light_len;
	light_rec.tmax = light_len;
	if (shadow_hit(s, light_ray, light_rec))
		return (TRUE);
	return (FALSE);
}

t_bool	shadow_hit(t_scene *s, t_ray light_ray, t_hit_record light_rec)
{
	int	i;

	i = 0;
	while (i < s->world[0]->size)
	{
		if (s->world[i]->type == CIRCLE)
		{
			if (hit_sphere((void *)s->world[i]->element, \
			&light_ray, &light_rec))
				return (TRUE);
		}
		else if (s->world[i]->type == PLANE)
		{
			if (hit_plane((void *)s->world[i]->element, &light_ray, &light_rec))
				return (TRUE);
		}
		else if (s->world[i]->type == CYLINDER)
		{
			if (hit_cylinder((void *)s->world[i]->element, \
			&light_ray, &light_rec))
				return (TRUE);
		}
		i++;
	}
	return (FALSE);
}
