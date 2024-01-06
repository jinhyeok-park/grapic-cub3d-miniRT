/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:19:41 by minjcho           #+#    #+#             */
/*   Updated: 2024/01/06 00:55:58 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_cylinder	*cylinder(t_point3 center, double radius, double height, \
					t_vec3 normal)
{
	t_cylinder	*ret;

	ret = malloc(sizeof(t_cylinder));
	ret->center = center;
	ret->radius = radius;
	ret->height = height;
	ret->normal = vunit(normal);
	return (ret);
}

void	handle_hit_side(t_cylinder *cy, t_ray *ray, \
						t_hit_record *rec, double t_side)
{
	t_vec3	normal;

	rec->t = t_side;
	rec->p = ray_at(ray, t_side);
	normal = vminus(vminus(rec->p, cy->center), vmult(cy->normal, \
					vdot(ray->dir, vmult(cy->normal, t_side)) + \
					vdot(vminus(ray->orig, cy->center), cy->normal)));
	rec->normal = vunit(normal);
	set_face_normal_cylinder(ray, rec, rec->normal);
}

void	handle_hit_caps(t_cylinder *cy, t_ray *ray, t_hit_record *rec, \
					double *caps)
{
	rec->t = caps[0];
	rec->p = ray_at(ray, caps[0]);
	if (caps[0] == caps[1])
		rec->normal = cy->normal;
	else
		rec->normal = vmult(cy->normal, -1);
	set_face_normal_cylinder(ray, rec, rec->normal);
}

t_bool	hit_cylinder(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
	double	t_side;
	double	caps[2];
	t_bool	hit_side;
	t_bool	hit_caps;

	t_side = INFINITY;
	caps[0] = INFINITY;
	hit_side = hit_cylinder_side(cy, ray, rec, &t_side);
	hit_caps = hit_cylinder_caps(cy, ray, rec, caps);
	if (hit_side && (!hit_caps || t_side < caps[0]))
	{
		handle_hit_side(cy, ray, rec, t_side);
		return (TRUE);
	}
	else if (hit_caps)
	{
		handle_hit_caps(cy, ray, rec, caps);
		return (TRUE);
	}
	return (FALSE);
}
