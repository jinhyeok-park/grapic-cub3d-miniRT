/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:19:41 by minjcho           #+#    #+#             */
/*   Updated: 2024/01/02 17:34:59y jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"
#include "cylinder.h"

#include <stdio.h>

t_cylinder *cylinder(t_point3 center, double radius, double height, t_vec3 normal)
{
	t_cylinder *ret;

	ret = malloc(sizeof(t_cylinder));
	ret->center = center;
	ret->radius = radius;
	ret->height  = height;
    ret->normal = vunit(normal);
	return (ret);
}

static void set_face_normal_cylinder(t_ray *r, t_hit_record *rec, t_vec3 outward_normal)
{
	rec->front_face = vdot(r->dir, outward_normal) < 0;
	rec->normal = rec->front_face ? outward_normal : vmult(outward_normal, -1);
}

t_bool hit_cylinder(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
    // C = cy->center;
    // A = cy->center * (cy->height / 2 * cy->normal);
    //
    t_vec3 x;
    double  a;
    double  b;
    double  c;
    double  dis;
    double  root;
    double  root1;
    double  sqrtd;
    double  dot;
    t_vec3  disc;
    t_vec3  rev;
    t_point3  p;
    t_vec3    v;
    double  t;
    double  d;

    rev = vmult(cy->normal, -1);
    dot = vdot(ray->dir, rev); // 내적하였을때 두 가지로 판단 할 수 있다. 
    if (dot < 0)
    {
        disc = vminus(cy->center, ray->orig);
        t = vdot(disc, rev) / dot;
        if (t >= 0)
        {
            p = ray_at(ray, t);
            v = vminus(p, cy->center);
            d = vdot(v, v);
            if (sqrtf(d) <= cy->radius)
            {
                rec->t = t;
                rec->p = p;
                rec->normal = rev;
                return TRUE;
            }
        }
    }
    dot = vdot(ray->dir, cy->normal);
    if (dot < 0)
    {
        t_point3 new_center;
        new_center = vplus(cy->center, vmult(cy->normal, cy->height));
        disc = vminus(new_center, ray->orig);
        t = vdot(disc, cy->normal) / dot;
        if (t >= 0)
        {
            p = ray_at(ray, t);
            v = vminus(p, new_center);
            d = vdot(v, v);
            if (sqrtf(d) <= cy->radius)
            {
                rec->t = t;
                rec->p = p;
                rec->normal = cy->normal;
                return TRUE;
            }
        }
    }
    x = vminus(ray->orig, cy->center);
    a = vdot(ray->dir, ray->dir) - pow((vdot(ray->dir, cy->normal)), 2);
    b = vdot(ray->dir, x) - vdot(ray->dir, cy->normal) * vdot(x, cy->normal);
    c = vdot(x, x) - pow(vdot(x, cy->normal), 2) - (cy->radius * cy->radius);

    dis = b * b - a * c;
    if (dis < 0)
    {
        //printf("hit false\n");
        return (FALSE);
    }
    sqrtd = sqrt(dis);
    root = (-b - sqrtd) / a;
    root1 = (-b + sqrtd) / a;

    if (root >= rec->tmin && root <= rec->tmax)
        root = root;
    else if (root1 >= rec->tmin && root1 <= rec->tmax)
        root = root1;
    else
        return FALSE;
    double  m;
    m = vdot(ray->dir, vmult(cy->normal, root)) + vdot(x, cy->normal);
    if (m > cy->height || m < 0)
        return FALSE;
    rec->t = root;
    rec->p = ray_at(ray, root);
    t_vec3  normal;
    normal = vminus(vminus(rec->p, cy->center), vmult(cy->normal, m));
    rec->normal = vunit(normal);

    set_face_normal_cylinder(ray, rec, rec->normal);
    return (TRUE);
}
