/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_hits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 22:19:12 by minjcho           #+#    #+#             */
/*   Updated: 2024/01/06 00:55:51 by minjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_bool	hit_cylinder_side(t_cylinder *cy, t_ray *ray, \
						t_hit_record *rec, double *t_side)
{
	t_cylinder_calc	calc;
	t_bool			hit;

	hit = FALSE;
	calc = calculate_cylinder_params(cy, ray);
	if (calc.discriminant < 0)
		return (FALSE);
	update_cylinder_roots_and_m(&calc, cy, ray);
	if (check_cylinder_root(calc.root, calc.m, rec, cy))
	{
		*t_side = calc.root;
		hit = TRUE;
	}
	if (check_cylinder_root(calc.root1, calc.m1, rec, cy) && \
						calc.root1 < *t_side)
	{
		*t_side = calc.root1;
		hit = TRUE;
	}
	return (hit);
}

t_bool	hit_cylinder_top_cap(t_cylinder *cy, t_ray *ray, \
						t_hit_record *rec, double *t_cap)
{
	t_vec3		to_top_cap;
	t_point3	p;
	t_bool		hit_cap;
	double		t_top;

	hit_cap = FALSE;
	to_top_cap = vminus(vplus(cy->center, vmult(cy->normal, cy->height)), \
						ray->orig);
	t_top = vdot(to_top_cap, cy->normal) / vdot(ray->dir, cy->normal);
	if (t_top >= rec->tmin && t_top <= rec->tmax)
	{
		p = ray_at(ray, t_top);
		if (vdot(vminus(p, vplus(cy->center, vmult(cy->normal, cy->height))), \
				vminus(p, vplus(cy->center, \
				vmult(cy->normal, cy->height)))) <= cy->radius * cy->radius)
		{
			*t_cap = t_top;
			hit_cap = TRUE;
		}
	}
	return (hit_cap);
}

t_bool	hit_cylinder_bottom_cap(t_cylinder *cy, t_ray *ray, \
							t_hit_record *rec, double *t_cap)
{
	t_vec3		to_bottom_cap;
	t_point3	p;
	t_bool		hit_cap;
	double		t_bottom;

	hit_cap = FALSE;
	to_bottom_cap = vminus(cy->center, ray->orig);
	t_bottom = vdot(to_bottom_cap, cy->normal) / vdot(ray->dir, cy->normal);
	if (t_bottom >= rec->tmin && t_bottom <= rec->tmax)
	{
		p = ray_at(ray, t_bottom);
		if (vdot(vminus(p, cy->center), vminus(p, cy->center)) <= \
						cy->radius * cy->radius)
		{
			if (t_bottom < *t_cap || *t_cap == 0)
			{
				*t_cap = t_bottom;
				hit_cap = TRUE;
			}
		}
	}
	return (hit_cap);
}

t_bool	hit_cylinder_caps(t_cylinder *cy, t_ray *ray, \
						t_hit_record *rec, double *t_cap)
{
	t_bool	hit_top;
	t_bool	hit_bottom;

	*t_cap = 0;
	hit_top = hit_cylinder_top_cap(cy, ray, rec, t_cap);
	hit_bottom = hit_cylinder_bottom_cap(cy, ray, rec, t_cap);
	return (hit_top || hit_bottom);
}
