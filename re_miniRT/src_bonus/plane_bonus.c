/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:03:54 by jinhyeok          #+#    #+#             */
/*   Updated: 2024/01/06 16:12:53 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_plane	*plane(t_point3 point, t_vec3 normal)
{
	t_plane	*ret;

	ret = malloc(sizeof(t_plane));
	ret->point = point;
	ret->normal = vunit(normal);
	return (ret);
}

t_bool	hit_plane(t_plane *p, t_ray *ray, t_hit_record *rec)
{
	double	dot;
	t_vec3	vec;
	double	t;

	dot = vdot(ray->dir, p->normal);
	if (fabs(dot) > 0)
	{
		vec = vminus(p->point, ray->orig);
		t = vdot(vec, p->normal) / dot;
		if (t >= 0)
		{
			rec->t = t;
			rec->p = vplus(ray->orig, vmult(ray->dir, t));
			if (dot > 0)
				rec->normal = vmult(p->normal, -1);
			else
				rec->normal = p->normal;
			return (TRUE);
		}
	}
	return (FALSE);
}
