/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:19:41 by minjcho           #+#    #+#             */
/*   Updated: 2024/01/05 12:24:22 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"
#include "cylinder.h"

#include <stdio.h>
#define EPSILON 1e-6

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

static void	set_face_normal_cylinder(t_ray *r, t_hit_record *rec, t_vec3 outward_normal)
{
	rec->front_face = vdot(r->dir, outward_normal) < 0;
	if (rec->front_face)
		rec->normal = outward_normal;
	else
		rec->normal = vmult(outward_normal, -1);
}

t_bool	hit_cylinder(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
	t_bool		hit_side;
	t_bool		hit_caps;
	double		t_side;
	double		t_cap;
	t_vec3		x;
	double		a;
	double		b;
	double		c;
	double		dis;
	double		sqrtd;
	double		root;
	double		root1;
	double		m;
	double		m1;
	double		t_top;
	t_vec3		to_top_cap;
	t_vec3		to_bottom_cap;
	double		t_bottom;
	t_point3	p;
	t_vec3		normal;

	hit_side = FALSE;
	hit_caps = FALSE;
	t_side = INFINITY;
	t_cap = INFINITY;
	x = vminus(ray->orig, cy->center);
	a = vdot(ray->dir, ray->dir) - pow(vdot(ray->dir, cy->normal), 2);
	b = 2 * (vdot(ray->dir, x) - vdot(ray->dir, cy->normal) * vdot(x, cy->normal));
	c = vdot(x, x) - pow(vdot(x, cy->normal), 2) - (cy->radius * cy->radius);
	dis = b * b - 4 * a * c;
	if (dis >= 0)
	{
		sqrtd = sqrt(dis);
		root = (-b - sqrtd) / (2 * a);
		root1 = (-b + sqrtd) / (2 * a);
		m = vdot(ray->dir, vmult(cy->normal, root)) + vdot(x, cy->normal);
		m1 = vdot(ray->dir, vmult(cy->normal, root1)) + vdot(x, cy->normal);
		if (m >= 0 && m <= cy->height && root >= rec->tmin && root <= rec->tmax)
		{
			t_side = root;
			hit_side = TRUE;
		}
		if (m1 >= 0 && m1 <= cy->height && root1 >= rec->tmin && root1 <= rec->tmax)
		{
			if (root1 < t_side)
			{
				t_side = root1;
				hit_side = TRUE;
			}
		}
	}
	if (fabs(vdot(ray->dir, cy->normal)) > EPSILON)
	{
		to_top_cap = vminus(vplus(cy->center, vmult(cy->normal, cy->height)), ray->orig);
		to_bottom_cap = vminus(cy->center, ray->orig);
		t_top = vdot(to_top_cap, cy->normal) / vdot(ray->dir, cy->normal);
		t_bottom = vdot(to_bottom_cap, cy->normal) / vdot(ray->dir, cy->normal);
		if (t_top >= rec->tmin && t_top <= rec->tmax)
		{
			p = ray_at(ray, t_top);
			if (vdot(vminus(p, vplus(cy->center, vmult(cy->normal, cy->height))), vminus(p, vplus(cy->center, vmult(cy->normal, cy->height)))) <= cy->radius * cy->radius)
			{
				t_cap = t_top;
				hit_caps = TRUE;
			}
		}
		if (t_bottom >= rec->tmin && t_bottom <= rec->tmax)
		{
			p = ray_at(ray, t_bottom);
			if (vdot(vminus(p, cy->center), vminus(p, cy->center)) <= cy->radius * cy->radius)
			{
				if (t_bottom < t_cap)
				{
					t_cap = t_bottom;
					hit_caps = TRUE;
				}
			}
		}
	}
	if (hit_side && (!hit_caps || t_side < t_cap))
	{
		rec->t = t_side;
		rec->p = ray_at(ray, t_side);
		normal = vminus(vminus(rec->p, cy->center), vmult(cy->normal, vdot(ray->dir, vmult(cy->normal, t_side)) + vdot(x, cy->normal)));
		rec->normal = vunit(normal);
		set_face_normal_cylinder(ray, rec, rec->normal);
		return (TRUE);
	}
	else if (hit_caps)
	{
		rec->t = t_cap;
		rec->p = ray_at(ray, t_cap);
		if (t_cap == t_top)
			rec->normal = cy->normal;
		else
			rec->normal = vmult(cy->normal, -1);
		set_face_normal_cylinder(ray, rec, rec->normal);
		return (TRUE);
	}
	return (FALSE);
}
